//
// Created by HeeSung Choi on 12/28/24.
//

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    jacobsthal.push_back(3);
    jacobsthal.push_back(5);
    jacobsthal.push_back(11);
    jacobsthal.push_back(21);
    jacobsthal.push_back(43);
    jacobsthal.push_back(85);
    jacobsthal.push_back(171);
    jacobsthal.push_back(341);
    jacobsthal.push_back(683);
    jacobsthal.push_back(1365);
    jacobsthal.push_back(2731);
    jacobsthal.push_back(5461);
    jacobsthal.push_back(10923);
    jacobsthal.push_back(21845);
    jacobsthal.push_back(43691);
    jacobsthal.push_back(87381);
    jacobsthal.push_back(174763);
    jacobsthal.push_back(349525);
    jacobsthal.push_back(699051);
    jacobsthal.push_back(1398101);
    jacobsthal.push_back(2796203);
    jacobsthal.push_back(5592405);
    jacobsthal.push_back(11184811);
    jacobsthal.push_back(22369621);
    jacobsthal.push_back(44739243);
    jacobsthal.push_back(89478485);
    jacobsthal.push_back(178956971);
    jacobsthal.push_back(357913941);
    jacobsthal.push_back(715827883);
    jacobsthal.push_back(1431655765);

    // INT MAX
    jacobsthal.push_back(2147483647);
}

PmergeMe::~PmergeMe() {
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if ( this != &other ) {
        *this = other;
    }

    return *this;
}

PmergeMe::PmergeMe(const PmergeMe& other) {
    *this = other;
}

std::vector<int> PmergeMe::sortVector(std::vector<int> const& data) {
    if ( data.size() <= 1 ) {
        return data;
    }

    std::vector<int> winner, looser;
    std::vector<std::pair<int, int> > chain;

    dividePair(data, winner, looser);
    makePair(winner, looser, chain);
    sortVector(winner);
    relocateLooser(winner, looser, chain);

    return insertByJacobsthal(winner, looser);
}

void PmergeMe::dividePair(std::vector<int> const& data, std::vector<int>& winner,
                          std::vector<int>& looser) {
    for ( size_t i = 0; i < data.size(); i += 2 ) {
        if ( data[i] <= data[i + 1] ) {
            winner.push_back(data[i]);
            looser.push_back(data[i + 1]);
        } else {
            winner.push_back(data[i + 1]);
            looser.push_back(data[i]);
        }
    }

    if ( data.size() & 1 ) {
        looser.push_back(data.back());
    }
}

void PmergeMe::makePair(std::vector<int> const& winner, std::vector<int> const& looser,
                        std::vector<std::pair<int, int> >& chain) {
    for ( size_t i = 0; i < winner.size(); i++ ) {
        chain.push_back(std::make_pair(winner[i], looser[i]));
    }

    if ( winner.size() < looser.size() ) {
        chain.push_back(std::make_pair(INT_MAX, looser.back()));
    }
}

void PmergeMe::relocateLooser(std::vector<int>& winner, std::vector<int>& looser,
                              std::vector<std::pair<int, int> >& chain) {
    std::vector<int> tmp;

    for ( size_t i = 0; i < winner.size(); i++ ) {
        std::pair<int, int> pair = findPair(chain, winner[i]);
        tmp.push_back(pair.second);
    }

    if ( tmp.size() < looser.size() ) {
        tmp.push_back(chain.back().second);
    }

    looser.assign(tmp.begin(), tmp.end());
}

std::pair<int, int> PmergeMe::findPair(std::vector<std::pair<int, int> > const& chain, int winner) {
    for ( size_t i = 0; i < chain.size(); i++ ) {
        if ( chain[i].first == winner ) {
            return chain[i];
        }
    }

    return std::make_pair(INT_MAX, INT_MAX);
}

std::vector<int> PmergeMe::insertByJacobsthal(std::vector<int> const& winner,
                                              std::vector<int> const& looser) {
    std::vector<int> result = winner;
    result.insert(result.begin(), 1, looser[0]);

    size_t num = 1;
    while ( getJacobsthal(num) < looser.size() ) {
        size_t right = std::min(getJacobsthal(num + 1), looser.size());
        size_t left = getJacobsthal(num);
        for ( size_t i = right; i > left; i-- ) {
            binaryInsert(result, 0, result.size(), looser[i - 1]);
        }
    }

    return result;
}

void PmergeMe::binaryInsert(std::vector<int>& data, size_t left, size_t right, size_t upper) {
    size_t mid = (left + right) / 2;
    if ( (size_t )data[mid] == upper ) {
        data.insert(data.begin() + mid, upper);
    } else if ( (size_t )data[mid] < upper ) {
        binaryInsert(data, mid + 1, right, upper);
    } else {
        binaryInsert(data, left, mid, upper);
    }
}

size_t PmergeMe::getJacobsthal(size_t n) {
    if ( n < jacobsthal.size() ) {
        return jacobsthal[n];
    }

    size_t jacobsthalNum = 2 * getJacobsthal(n - 1) - getJacobsthal(n - 2);
    jacobsthal.push_back(jacobsthalNum);

    return jacobsthal.back();
}