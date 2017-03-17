#ifndef BIGINTEGER_H
#define BIGINTEGER_H

class BigInteger {
private:
	std::string numString;
	std::stack<char> numStack;

public:
	BigInteger();
	BigInteger( std::string s );

	friend std::istream &operator >> ( std::istream &input, BigInteger &a );
	friend std::ostream &operator << ( std::ostream &output, BigInteger &a );

	bool operator > ( const BigInteger& a );
	bool operator < ( const BigInteger& a );
	bool operator == (const BigInteger& a );

	BigInteger operator + ( BigInteger& rhs );
	BigInteger operator * ( BigInteger& rhs );
};
#endif