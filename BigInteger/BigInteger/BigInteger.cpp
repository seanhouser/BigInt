// BigInteger.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "BigInteger.hpp"

int _tmain(int argc, _TCHAR* argv[])
{
	BigInteger bInt("123412341234");
	BigInteger sInt("1234");

	std::cout << bInt + sInt << '\n';

	return 0;
}