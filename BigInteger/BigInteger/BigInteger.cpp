// BigInteger.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "BigInteger.hpp"

int _tmain(int argc, _TCHAR* argv[])
{
	BigInteger bInt("300000000000");
	BigInteger sInt("50");

	std::cout << bInt << '\n' << sInt << '\n';

	return 0;
}

