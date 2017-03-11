// BigInteger.cpp : Defines the entry point for the console application.
// TEST DRIVER FOR BigInteger.hpp

#include "stdafx.h"
#include <iostream>
#include "BigInteger.hpp"

int _tmain(int argc, _TCHAR* argv[])
{
	BigInteger bInt("10000000099");
	BigInteger sInt("987");

	//test copy
	std::cout << bInt << '\n' << sInt << '\n';
	BigInteger bacon = sInt;
	sInt = bInt;
	std::cout << bInt << '\n' << sInt << '\n';

	//test input
	std::cout << "\nPlease enter new input for sInt: ";
	std::cin >> sInt;
	std::cout << bInt << '\n' << sInt << '\n';

	//test add
	BigInteger result = bInt + sInt;
	std::cout << result  << '\n';
	//std::cout << bInt + sInt << '\n' << bInt << '\n' << sInt << std::endl;


	return 0;
}