#ifndef BIGINTEGER_H
#define BIGINTEGER_H

/*	- Only works on positive numbers
	- BigInteger value must be passed as a string parameter
*/

#include <iostream>
#include <vector>
#include <sstream>

class BigInteger {
public:
	//default constructor
	BigInteger() {
	};

	//constructor, loads character array value with NULL-terminated int
	//loads number of digits into size
	BigInteger::BigInteger( std::string v ) {
		value = v;
		int temp;
		for (size=0; v[size] != '\0'; ++size) {		//set size
			std::stringstream str;					//inside loop to clear buffer for every char
			str << v[size];
			str >> temp;
			digits.push_back(temp);
		}
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
		

		return result;
	}


private:
	std::string value;
	int size;
	std::vector<int> digits;
};

#endif