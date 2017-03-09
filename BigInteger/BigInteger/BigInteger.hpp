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

	//constructor, loads character array value with NULL-terminated int
	//loads number of digits into size
	BigInteger::BigInteger( std::string s ) {
		value = s;
		int temp;
		for (size=0; s[size] != '\0'; ++size) {		//set data member size and initialize stack
			stack.push(s[size]);
		}
		std::vector<char> v(s.begin(), s.end());	//initialize vector
		digits = v;									
	};

	//output operator
	friend std::ostream &operator<< ( std::ostream &output, BigInteger &a ) {
		output << a.value;
		return output;
	}

	//input operator
	friend std::istream &operator>> ( std::istream &input, BigInteger &a ) {
		input >> a.value;
		return input;
	}

	//addition operator
	BigInteger operator+ ( BigInteger& rhs ) {
		BigInteger result;
		std::stack<char> tempStack = stack;
		std::stack<char> rhsTempStack = rhs.stack;


		while (!tempStack.empty() && !rhsTempStack.empty()) {
			std::cout << tempStack.top() << " + " << rhsTempStack.top() << '\n';			
			tempStack.pop();
			rhsTempStack.pop();
		}

		/*if (rhsTempStack.empty()) {
			while (!tempStack.empty()) {
				std::cout << tempStack.top() << " + NONE\n" ;
				tempStack.pop();
			}
		}
		else if (tempStack.empty()) {
			while (!rhsTempStack.empty()) {
				std::cout << rhsTempStack.top() << " + NONE\n" ;
				rhsTempStack.pop();

		}*/

		return result;
	}


private:
	std::string value;
	int size;
	std::vector<char> digits;
	std::stack<char> stack;
};

#endif