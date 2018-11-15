#include "ScalarBool.h"
#include <iostream>
#include <iomanip>
#include "SBTester.h"

int main(void)
{
	ScalarBool::ScalarBool sb1;
	
	sb1 = true;
	std::cout << sb1 << std::endl;
	sb1 = false;
	std::cout << sb1 << std::endl;

	std::cout << std::boolalpha << (sb1 == true) << std::endl;
	sb1 = true;
	std::cout << std::boolalpha << (sb1 == true) << std::endl;

	sb1 = 4.2;
	std::cout << sb1 << std::endl;
	sb1 = .7;
	std::cout << sb1 << std::endl;
	sb1.flip();
	std::cout << sb1 << std::endl;
	sb1.cap();
	std::cout << sb1 << std::endl;
	sb1 = .4;
	sb1.cap();
	std::cout << sb1 << std::endl;
}