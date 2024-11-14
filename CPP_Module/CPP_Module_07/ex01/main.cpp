//
// Created by Heesung Choi on 11/14/24.
//

#include "iter.hpp"
#include <iostream>

int main() {
	int intArray[] = {1, 2, 3, 4, 5};
	iter(intArray, 5, print);
	std::cout << std::endl;

	std::string strArray[] = {"Hello", "World", "!"};
	iter(strArray, 3, print);
	std::cout << std::endl;

	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	iter(doubleArray, 5, print);
	std::cout << std::endl;

	return 0;
}
