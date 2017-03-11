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
	std::cout << bInt << '\n' << sInt << '\n';
	BigInteger bacon = sInt;
	sInt = bInt;
	std::cout << bInt << '\n' << sInt << '\n';
	
	//test input
	std::cout << "\nPlease enter new input for sInt: ";
	std::cin >> sInt;
	std::cout << bInt << '\n' << sInt << '\n';

	//test >
	//bool test = bInt > sInt;
	//std::cout << "Greater than: " << test << '\n';
	//test = sInt > bInt;
	//std::cout << "Greater than: " << test << '\n';
	//test = sInt > sInt;
	/*^^^^ CRASH WHEN COMPARING TWO OF THE SAME OBJECT ^^^^*/
	//std::cout << "Greater than: " << test << '\n';

	//test add
	std::cout << bInt + sInt << '\n';
	std::cout << bInt + sInt << '\n' << bInt << '\n' << sInt << std::endl;


	return 0;
}