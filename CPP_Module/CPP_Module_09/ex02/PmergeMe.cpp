//
// Created by HeeSung Choi on 12/28/24.
//

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		*this = other;
	}

	return *this;
}

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}

void PmergeMe::sortVector(std::vector<int> &data) const {
    if (data.size() <= 1) {
        return;
    }

    std::vector<int> a, b;
    std::vector<std::pair<int, int>> chain;
    pairWiseComparision(data, a, b);
    storeMapping(a, b, chain);
    sortVector(a);
    permuteSmallerHalf(a, b, chain);
    batchInsertion(a, b, data);
}

void PmergeMe::pairWiseComparision(std::vector<int> &data, std::vector<int> &a, std::vector<int> &b) const {
    for (size_t i = 1; i < data.size(); i += 2) {
        if (data[i - 1] < data[i]) {
            a.push_back(data[i - 1]);
            b.push_back(data[i]);
        } else {
            a.push_back(data[i]);
            b.push_back(data[i - 1]);
        }
    }

    if (data.size() & 1) {
        b.push_back(data[data.size() - 1]);
    }
}

void PmergeMe::storeMapping(std::vector<int> &a, std::vector<int> &b, std::vector <std::pair<int, int>> &chain) const {
    for (size_t i = 0; i < a.size(); ++i) {
        chain.push_back(std::make_pair(a[i], b[i]));
    }

    if (a.size() < b.size()) {
        chain.push_back(std::make_pair(INT_MAX, b[b.size() - 1]));
    }
}

void PmergeMe::permuteSmallerHalf(std::vector<int> &a, std::vector<int> &b,
                                  std::vector <std::pair<int, int>> &chain) const {
    std::vector<std::pair<int, int>> newChain;
    for (size_t i = 0; i < a.size(); ++i) {
        std::vector<std::pair<int, int>> pair = findPairByFirstValue(chain, a[i]);
    }
}

void PmergeMe::findPairFirstValue(std::vector <std::pair<int, int>> &chain, int value) {

}