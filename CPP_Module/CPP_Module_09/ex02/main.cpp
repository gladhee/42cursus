//
// Created by Heesung Choi on 11/21/24.
//

#include "PmergeMe.hpp"

void measurePerformanceVector(std::vector<int>& container, PmergeMe &p);
void measurePerformanceDeque(std::deque<int>& container, PmergeMe &p);

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " [number1] [number2] [number3] ..." << std::endl;
		return 1;
	}

	PmergeMe p;
	std::vector<int> vec;
	std::deque<int> deq;

	try {
		initData(vec, argv);
		initData(deq, argv);
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	std::cout << "Before: ";
	printData(vec);

	measurePerformanceVector(vec, p);
	measurePerformanceDeque(deq, p);
}

void measurePerformanceVector(std::vector<int>& vec, PmergeMe &p) {
	std::clock_t start = std::clock();
	p.sortVector(vec);
	std::clock_t end = std::clock();

	double elapsedTime = (1000000.0 * (end - start)) / CLOCKS_PER_SEC;

	std::cout << "After(vec): ";
	printData(vec);


	// 형식 출력
	std::cout << "Time to process a range of " << vec.size()
			  << " elements with std::vector : " << std::fixed << std::setprecision(5)
			  << elapsedTime << " us" << std::endl;
}

void measurePerformanceDeque(std::deque<int>& deq, PmergeMe &p) {
	std::clock_t start = std::clock();
	std::vector<int> sortedDeq = p.sortDeque(deq);
	std::clock_t end = std::clock();

	double elapsedTime = (1000000.0 * (end - start)) / CLOCKS_PER_SEC;

	std::cout << "Time to process a range of " << deq.size()
			  << " elements with std::vector : " << std::fixed << std::setprecision(5)
			  << elapsedTime << " us" << std::endl;
}
