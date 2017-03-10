// BigInteger.cpp : Defines the entry point for the console application.
// TEST DRIVER FOR BigInteger.hpp

#include "stdafx.h"
#include <iostream>
#include "BigInteger.hpp"

int _tmain(int argc, _TCHAR* argv[])
{
	BigInteger bInt("10000000099");
	BigInteger sInt("99");

	std::cin >> sInt;

	BigInteger result = bInt + sInt;

	std::cout << result << '\n';

	return 0;
}