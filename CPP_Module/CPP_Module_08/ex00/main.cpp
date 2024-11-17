//
// Created by Heesung Choi on 11/14/24.
//

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
	std::vector<int> vec;

	for (int i = 0; i < 5; i++) {
		vec.push_back(i * 2);
	}

	for (int i = 0; i < 10; i++) {
		std::vector<int>::iterator it = easyfind(vec, i);
		if (it != vec.end()) {
			std::cout << "Found " << i << std::endl;
		} else {
			std::cout << "Not found " << i << std::endl;
		}
	}

	return 0;
}
