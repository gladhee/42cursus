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
