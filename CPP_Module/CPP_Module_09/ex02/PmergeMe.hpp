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

public:
	PmergeMe();

	~PmergeMe();

	void sortVector(std::vector<int> &data) const;

	void sortDeque(std::deque<int> &data) const;


private:

    PmergeMe &operator=(const PmergeMe &other);

    PmergeMe(const PmergeMe &other);

    void pairWiseComparision(std::vector<int> &data, std::vector<int> &a, std::vector<int> &b) const;
    void storeMapping(std::vector<int> &a, std::vector<int> &b, std::vector<std::pair<int, int>> &chain) const;
    void permuteSmallerHalf(std::vector<int> &a, std::vector<int> &b, std::vector<std::pair<int, int>> &chain) const;
    void batchInsertion(std::vector<int> &a, std::vector<int> &b, std::vector<int> &data) const;
    void findPairFirstValue(std::vector<std::pair<int, int>>& chain, int value);
};

template<typename Container>
void initData(Container &container, char **argv) {

	for (int i = 1; argv[i]; i++) {
		std::istringstream iss(argv[i]);
		long long num;

		iss >> num;

		if (iss.fail() || num <= 0 || num > INT_MAX) {
			throw std::invalid_argument("Invalid argument");
		}

		if (std::find(container.begin(), container.end(), num) != container.end()) {
			throw std::invalid_argument("Duplicate number");
		}

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
