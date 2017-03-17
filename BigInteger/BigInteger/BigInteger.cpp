/*	- BigInteger value must be passed as a string parameter	
	- Only works on positive numbers
	- Does not account for leading zeros in comparison operations
	- overloaded >>, <<, +, *, >, <, ==
*/

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <stack>
#include "BigInteger.hpp"

const int ASCII_OFFSET = 48;

int _tmain(int argc, _TCHAR* argv[])
{
	BigInteger bInt("100");
	BigInteger sInt("1");

	//test copy
	//std::cout << bInt << '\n' << sInt << '\n';
	//BigInteger bacon = sInt;
	//sInt = bInt;
	//std::cout << bInt << '\n' << sInt << '\n';
	
	//test input
	//std::cout << "\nPlease enter new input for sInt: ";
	//std::cin >> sInt;
	//std::cout << bInt << '\n' << sInt << '\n';

	//test >
	//bool test = bInt > sInt;
	//std::cout << bInt << " is greater than " << sInt << ": " << test << '\n';
	//test = sInt > bInt;
	//std::cout << sInt << " is greater than " << bInt << ": " << test << '\n';
	//test = sInt > sInt;
	//std::cout << sInt << " is greater than " << sInt << ": " << test << '\n';

	//test <
	//bool test = bInt < sInt;
	//std::cout << bInt << " is less than " << sInt << ": " << test << '\n';
	//test = sInt < bInt;
	//std::cout << sInt << " is less than " << bInt << ": " << test << '\n';
	//test = sInt < sInt;
	//std::cout << sInt << " is less than " << sInt << ": " << test << '\n';

	//test == 
	//bool result = bInt == sInt;
	//std::cout << bInt << " is equal to " << sInt << ": " << result << '\n';
	//bInt = sInt;
	//result = bInt == sInt;
	//std::cout << bInt << " is equal to " << sInt << ": " << result << '\n';

	//test <
	//bool test = bInt > sInt;
	//std::cout << bInt << " is greater than: " << sInt << ": " << test << '\n';
	//test = sInt > bInt;
	//std::cout << sInt << " is greater than: " << bInt  << ": " << test << '\n';
	//test = sInt > sInt;
	//std::cout << sInt << " is greater than: " << sInt << ": " << test << '\n';

	//test add
	//std::cout << bInt + sInt << '\n';
	//std::cout << bInt + sInt << '\n' << bInt << '\n' << sInt << std::endl;

	//test mul
	//std::cout << bInt * sInt << '\n';


	return 0;
}

//default constructor
BigInteger::BigInteger() {};

// constructor
BigInteger::BigInteger( std::string s ) {
	numString = s;
	for (int i=0; s[i] != '\0'; ++i)
		numStack.push(s[i]);							
};

// input operator
std::istream &operator >> ( std::istream &input, BigInteger &a ) {
	std::string s;
	input >> a.numString;
		
	int initSize = a.numStack.size();
	for (int i=0; i<initSize; ++i)
		a.numStack.pop();
	for (int i=0; a.numString[i] != '\0'; ++i)
		a.numStack.push(a.numString[i]);
	return input;
}

// output operator
std::ostream &operator << ( std::ostream &output, BigInteger &a ) {
	output << a.numString;
	return output;
}

// > operator
/* THIS WONT WORK WITH INTS OF THE SAME NUMBER OF DIGITS WHERE THE DIFFERENCE ISN'T THE LEFT-MOST DIGIT */
bool BigInteger::operator > ( const BigInteger& a ) {
	if (this->numStack.size() > a.numStack.size())
		return true;
	else if (this->numStack.size() < a.numStack.size())
		return false;
	else if (this->numStack.size() == a.numStack.size()) {
		std::stack<char> lhs = this->numStack;
		std::stack<char> rhs = a.numStack;
		char leftOperand, rightOperand;
		while (!lhs.empty()) {
			leftOperand = lhs.top();
			lhs.pop();
		}
		while (!rhs.empty()) {
			rightOperand = rhs.top();
			rhs.pop();
		}
		if (leftOperand > rightOperand)
			return true;
		else
			return false;
	}
}

// < operator
/* THIS WONT WORK WITH INTS OF THE SAME NUMBER OF DIGITS WHERE THE DIFFERENCE ISN'T THE LEFT-MOST DIGIT */
bool BigInteger::operator < ( const BigInteger& a ) {
	if (this->numStack.size() < a.numStack.size())
		return true;
	else if (this->numStack.size() > a.numStack.size())
		return false;
	else if (this->numStack.size() == a.numStack.size()) {
		std::stack<char> lhs = this->numStack;
		std::stack<char> rhs = a.numStack;
		char leftOperand, rightOperand;
		while (!lhs.empty()) {
			leftOperand = lhs.top();
			lhs.pop();
		}
		while (!rhs.empty()) {
			rightOperand = rhs.top();
			rhs.pop();
		}
		if (leftOperand < rightOperand)
			return true;
		else
			return false;
	}
}

// == operator
bool BigInteger::operator == (const BigInteger& a ) {
	bool result;
	std::stack<char> lhs = this->numStack;
	std::stack<char> rhs = a.numStack;
	if (lhs.size() != rhs.size())
		result = false;
	else {
		result = true;
		for (int i=0; i<lhs.size(); ++i) {
			if (lhs.top() != rhs.top())
				result = false;
			lhs.pop();
			rhs.pop();
		}
	}
	return result;
}

// addition operator
BigInteger BigInteger::operator + ( BigInteger& rhs ) {
	BigInteger result;					//BigInteger object to return
	std::stack<char> resultStack;		//stack for maintaining results of addition, later assigned to BigInt stack for return
	std::stack<char> largeNumStack;		//temporary stack for larger number
	std::stack<char> smallNumStack;		//temporary stack for smaller number

	//initialize the larger of the BigInts to largeNumStack and the smaller or equal BigInt to smallNumStack
	if (this->numStack.size() >= rhs.numStack.size()) {
		largeNumStack = this->numStack;
		smallNumStack = rhs.numStack;
	}
	else {
		largeNumStack = rhs.numStack;
		smallNumStack = this->numStack;
	}

	//addition operation
	bool carry = false;
	while (!largeNumStack.empty() && !smallNumStack.empty()) {
		char c = (largeNumStack.top()+smallNumStack.top()) - ASCII_OFFSET;
		if (carry == 1) {
			c += 1; 
			carry = false;
		}
		if (c > 57) {
			c -= 10;
			carry = true;
		}
		resultStack.push(c);
		largeNumStack.pop();
		smallNumStack.pop();
	}

	//for pushing digits of largeNumStack greater than smallNumStack has
	if (smallNumStack.empty()) {
		while (!largeNumStack.empty()) {
			if (carry == true) {
				if (largeNumStack.top() != '9') {		//if top of stack is 9, cannot increment. Pop 9 and push 0 and keep carry = true
					++largeNumStack.top();
					carry = false;
				}
				else {
					largeNumStack.pop();
					largeNumStack.push('0');
				}
			}
			resultStack.push(largeNumStack.top());
			largeNumStack.pop();
		}
	}
	if (carry)
		resultStack.push('1');
		

	//initialize BigInt obj stack and string with results and return it
	int count = resultStack.size();
	while (count) {
		result.numStack.push(resultStack.top());
		result.numString += resultStack.top();
		resultStack.pop();
		--count;
	}

	return result;
}

// multiplication operator
BigInteger BigInteger::operator * ( BigInteger& rhs ) {
	BigInteger result;					//BigInteger object to return
	BigInteger largeObj;				//temporary BigInteger object for larger number
	BigInteger smallObj;				//temporary BigInteger object for smaller number

	//initialize the larger of the BigInts to largeNumStack and the smaller or equal BigInt to smallNumStack
	if (this->numStack.size() >= rhs.numStack.size()) {
		largeObj = *this;
		smallObj = rhs;
	}
	else {
		largeObj = rhs;
		smallObj = *this;
	}

	//zero case, then multiply
	if (largeObj.numStack.size() == 1 && largeObj.numStack.top() == '0' || smallObj.numStack.size() == 1 && smallObj.numStack.top() == '0') {
		result.numStack.push('0');
		result.numString = "0";
	}
	else {
		int digitCount = 1;
		while (!smallObj.numStack.empty()) {
			int loop = (smallObj.numStack.top() - ASCII_OFFSET) * digitCount;
			while (loop > 0) {
				result = result + largeObj;
				--loop;
			}
			smallObj.numStack.pop();
			smallObj.numString.pop_back();
			digitCount *= 10;
		}
	}
	return result;
}