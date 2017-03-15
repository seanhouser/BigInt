// BigInteger.cpp : Defines the entry point for the console application.
// TEST DRIVER FOR BigInteger.hpp

#include "stdafx.h"
#include <iostream>
#include "BigInteger.hpp"

int _tmain(int argc, _TCHAR* argv[])
{
	BigInteger bInt("101");
	BigInteger sInt("11");


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
	bool test = bInt < sInt;
	std::cout << bInt << " is less than " << sInt << ": " << test << '\n';
	test = sInt < bInt;
	std::cout << sInt << " is less than " << bInt << ": " << test << '\n';
	test = sInt < sInt;
	std::cout << sInt << " is less than " << sInt << ": " << test << '\n';

	//test <
	//bool test = bInt > sInt;
	//std::cout << "Greater than: " << test << '\n';
	//test = sInt > bInt;
	//std::cout << "Greater than: " << test << '\n';
	//test = sInt > sInt;
	//std::cout << "Greater than: " << test << '\n';

	//test add
	//std::cout << bInt + sInt << '\n';
	//std::cout << bInt + sInt << '\n' << bInt << '\n' << sInt << std::endl;


	return 0;
}