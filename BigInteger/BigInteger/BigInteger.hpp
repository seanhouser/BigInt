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
public:
	//default constructor
	BigInteger() {
	};

	//constructor, loads character stack with passed param
	//loads number of digits into size
	BigInteger::BigInteger( std::string s ) {
		value = s;
		int temp;
		for (size=0; s[size] != '\0'; ++size) {		//set data member size and initialize stack
			stack.push(s[size]);
		}								
	};

	//output operator
	friend std::ostream &operator<< ( std::ostream &output, BigInteger &a ) {
		//output << a.value;
		for (int i=0; i<a.size; ++i) {
			char c;
			c = a.stack.top();
			output << c;
			a.stack.pop();
		}
		return output;
	}

	//input operator
	friend std::istream &operator>> ( std::istream &input, BigInteger &a ) {
		
		return input;
	}

	//addition operator
	BigInteger operator+ ( BigInteger& rhs ) {
		BigInteger result;					//BigInteger object to return
		std::stack<char> resultStack;		//stack for maintaining results of addition, later assigned to BigInt stack for return
		std::stack<char> largeNumStack;		//temporary stack for larger number
		std::stack<char> smallNumStack;		//temporary stack for smaller number

		//initialize the larger of the BigInts to largeNumStack and the smaller or equal BigInt to smallNumStack
		if (this->size >= rhs.size) {
			largeNumStack = this->stack;
			smallNumStack = rhs.stack;
		}
		else {
			largeNumStack = rhs.stack;
			smallNumStack = this->stack;
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
		
		//initialize BigInt obj with results and size and return it
		result.stack = resultStack;
		result.size = resultStack.size();
		return result;
	}


private:
	std::string value;
	int size;
	std::stack<char> stack;
};

#endif