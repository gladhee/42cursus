//
// Created by Heesung Choi on 11/21/24.
//

#include "PmergeMe.hpp"

void measurePerformanceVector(std::vector<int>& container);
void measurePerformanceDeque(std::deque<int>& container);

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " [number1] [number2] [number3] ..." << std::endl;
		return 1;
	}

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

	measurePerformanceVector(vec);
	measurePerformanceDeque(deq);
}

void measurePerformanceVector(std::vector<int>& vec) {
    PmergeMe p;
	std::clock_t start = std::clock();
	std::vector<int> ret = p.sortVector(vec);
	std::clock_t end = std::clock();

    double time = (static_cast<double>(end - start) * 1000) / CLOCKS_PER_SEC;

	std::cout << "After(vec): ";
	printData(ret);


	// 형식 출력
	std::cout << "Time to process a range of " << vec.size()
			  << " elements with std::vector : "
			  << time << " us" << std::endl;
}

void measurePerformanceDeque(std::deque<int>& deq) {
    PmergeMe p;
	std::clock_t start = std::clock();
	std::deque<int> ret = p.sortDeque(deq);
	std::clock_t end = std::clock();

    double time = (static_cast<double>(end - start) * 1000) / CLOCKS_PER_SEC;

    std::cout << "After(deq): ";
    printData(ret);

	std::cout << "Time to process a range of " << deq.size()
			  << " elements with std::deque : "
			  << time << " us" << std::endl;
}
