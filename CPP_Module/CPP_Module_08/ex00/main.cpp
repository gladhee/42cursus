//
// Created by Heesung Choi on 11/14/24.
//

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
	std::cout << "non-const vector\n" << std::endl;

	std::vector<int> vec;

	for (int i = 0; i < 5; i++) {
		vec.push_back(i * 2);
	}

	try {
		std::vector<int>::iterator it = easyfind(vec, 1);
		std::cout << "Value found: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::vector<int>::iterator it = easyfind(vec, 2);
		std::cout << "Value found: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::vector<int>::iterator it = easyfind(vec, 3);
		std::cout << "Value found: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::vector<int>::iterator it = easyfind(vec, 4);
		std::cout << "Value found: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n\nconst vector\n" << std::endl;

	std::vector<int> const vec2 = vec;

	try {
		std::vector<int>::const_iterator it = easyfind(vec2, 1);
		std::cout << "Value found: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::vector<int>::const_iterator it = easyfind(vec2, 2);
		std::cout << "Value found: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::vector<int>::const_iterator it = easyfind(vec2, 3);
		std::cout << "Value found: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::vector<int>::const_iterator it = easyfind(vec2, 4);
		std::cout << "Value found: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}


	return 0;
}
