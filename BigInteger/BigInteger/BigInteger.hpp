#ifndef BIGINTEGER_H
#define BIGINTEGER_H

/*	- Only works on positive numbers
	- BigInteger value must be passed as a string parameter
	- constructor, default constructor
	- overloaded +, >>, <<
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <stack>

class BigInteger {
private:
//member data
	std::string numString;
	std::stack<char> numStack;

public:
//default constructor
	BigInteger() {};

//constructor
	BigInteger::BigInteger( std::string s ) {
		numString = s;
		for (int i=0; s[i] != '\0'; ++i)
			numStack.push(s[i]);							
	};

//input operator
	friend std::istream &operator>> ( std::istream &input, BigInteger &a ) {
		std::string s;
		input >> a.numString;
		
		int initSize = a.numStack.size();
		for (int i=0; i<initSize; ++i)
			a.numStack.pop();
		for (int i=0; a.numString[i] != '\0'; ++i)
			a.numStack.push(a.numString[i]);
		return input;
	}

//output operator
	friend std::ostream &operator<< ( std::ostream &output, BigInteger &a ) {
		output << a.numString;
		return output;
	}

//> operator
	 bool operator <(const BigInteger& a) {
		 return true;
	 }

//addition operator
	BigInteger operator+ ( BigInteger& rhs ) {
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
		int carry = 0;
		while (!largeNumStack.empty() && !smallNumStack.empty()) {
			char c = (largeNumStack.top()+smallNumStack.top())-48;
			if (carry == 1) {
				c += 1; 
				carry = 0;
			}
			if (c > 57) {
				c -= 10;
				carry = 1;
			}
			resultStack.push(c);
			largeNumStack.pop();
			smallNumStack.pop();
		}

		//for pushing digits of largeNumStack greater than smallNumStack has
		if (smallNumStack.empty()) {
			while (!largeNumStack.empty()) {
				//std::cout << largeNumStack.top() << " + NONE\n" ;
				if (carry == 1) {
					++largeNumStack.top();
					carry = 0;
				}
				resultStack.push(largeNumStack.top());
				largeNumStack.pop();
			}
		}
		
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
};

#endif