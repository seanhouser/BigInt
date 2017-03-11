#ifndef BIGINTEGER_H
#define BIGINTEGER_H

/*	- Only works on positive numbers
	- BigInteger value must be passed as a string parameter
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
	int size;

public:
//default constructor
	BigInteger() {};

//constructor
	BigInteger::BigInteger( std::string s ) {
		numString = s;
		for (size=0; s[size] != '\0'; ++size)		//set size in for loop predicate and initialize stack
			numStack.push(s[size]);							
	};

//copy constructor
	BigInteger( BigInteger &a ) {
		BigInteger tempInt;							//temp BigInt obj for restoring this BigInt obj	

/*^^^^	
		YOU IDIOT, LOAD A TEMP THEN USE IT, LIKE WITH ADDITION 
		DON'T CREATE A WHOLE TEMP, LOAD IT, THEN DESTROY THE ORIGINAL, THEN RELOAD THE ORIGINAL FROM THE TEMP
  ^^^^*/

		numString = a.numString;
		size = a.size;
		for (int i=0; i<a.size; ++i) {
			tempInt.numStack.push(numStack.top());	//push to temp BigInt obj for storage
			a.numStack.push(numStack.top());		//push to new BigInt obj
			numStack.pop();
		}			
		for (int i=0; i<a.size; ++i) {				//restore this BigInt object from temp BigInt obj
			numStack.push(tempInt.numStack.top());
			tempInt.numStack.pop();
		}
	}

//input operator
	friend std::istream &operator>> ( std::istream &input, BigInteger &a ) {
		std::string s;
		input >> a.numString;
		
		for (int i=0; i<a.size; ++i)
			a.numStack.pop();
		for (a.size=0; a.numString[a.size] != '\0'; ++a.size)	//set data member size in for loop pred and initialize stack
			a.numStack.push(a.numString[a.size]);
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
		if (this->size >= rhs.size) {
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

		//for pushing digits of largeNumStack larger than smallNumStack has
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
		
		//initialize BigInt obj stack, string, and size with results and return it
		
		
		//result.size = resultStack.size();
/*^^^^	WHY CAN'T I SET SIZE AND RETURN WITHOUT CRASHING??
  ^^^^ */

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