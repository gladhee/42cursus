//
// Created by HeeSung Choi on 12/28/24.
//

#ifndef CPP_MODULE_09_PMERGEME_HPP
#define CPP_MODULE_09_PMERGEME_HPP

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

class PmergeMe {
private:
    std::vector<int> jacobsthal;

public:
    PmergeMe();

    ~PmergeMe();

    std::vector<int> sortVector(std::vector<int> const &data);

    std::deque<int> sortDeque(std::deque<int> const &data);

private:
    PmergeMe &operator=(const PmergeMe &other);

    PmergeMe(const PmergeMe &other);

    void dividePair(std::vector<int> const &data, std::vector<int> &winner,
                    std::vector<int> &looser);

    void makePair(std::vector<int> const &winner, std::vector<int> const &looser,
                  std::vector <std::pair<int, int> > &chain);

    void relocateLooser(std::vector<int> &winner, std::vector<int> &looser,
                        std::vector <std::pair<int, int> > &chain);

    std::pair<int, int> findPair(std::vector <std::pair<int, int> > const &chain, int winner);

    std::vector<int> insertByJacobsthal(std::vector<int> const &winner,
                                        std::vector<int> const &looser);

    void binaryInsert(std::vector<int> &data, size_t left, size_t right, int value);

    size_t getJacobsthal(size_t n);

    void dividePair(std::deque<int> const &data, std::deque<int> &winner,
                    std::deque<int> &looser);

    void makePair(std::deque<int> const &winner, std::deque<int> const &looser,
                  std::deque <std::pair<int, int> > &chain);

    void relocateLooser(std::deque<int> &winner, std::deque<int> &looser,
                        std::deque <std::pair<int, int> > &chain);

    std::pair<int, int> findPair(std::deque <std::pair<int, int> > const &chain, int winner);

    std::deque<int> insertByJacobsthal(std::deque<int> const &winner,
                                        std::deque<int> const &looser);

    void binaryInsert(std::deque<int> &data, size_t left, size_t right, int value);
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

//        if (std::find(container.begin(), container.end(), num) != container.end()) {
//            throw std::invalid_argument("Duplicate number");
//        }

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

template<typename Container>
bool isSorted(Container &container) {
    for (typename Container::iterator it = container.begin(); it != container.end() - 1; it++) {
        if (*it > *(it + 1)) {
            return false;
        }
    }
    return true;
}

#endif  // CPP_MODULE_09_PMERGEME_HPP
