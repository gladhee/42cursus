//
// Created by HeeSung Choi on 12/28/24.
//

#ifndef CPP_MODULE_09_PMERGEME_HPP
#define CPP_MODULE_09_PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <iomanip>

class PmergeMe {

private:

	PmergeMe &operator=(const PmergeMe &other);

	PmergeMe(const PmergeMe &other);


public:
	PmergeMe();

	~PmergeMe();

	void sortVector(std::vector<int> &data) {
		std::sort(data.begin(), data.end());
	}

	void sortDeque(std::deque<int> &data) {
		std::sort(data.begin(), data.end());
	}
};

template<typename Container>
void initData(Container &container, char **argv) {

	for (int i = 1; argv[i]; i++) {
		std::istringstream iss(argv[i]);
		int num;
		iss >> num;
		if (iss.fail() || num <= 0) {
			throw std::invalid_argument("Invalid argument");
		}

//		if (std::find(container.begin(), container.end(), num) != container.end()) {
//			throw std::invalid_argument("Duplicate number");
//		}
		container.push_back(num);
	}
}

template<typename Container>
void printData(Container &container) {
	for (typename Container::iterator it = container.begin(); it != container.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

#endif //CPP_MODULE_09_PMERGEME_HPP
