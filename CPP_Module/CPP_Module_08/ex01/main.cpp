//
// Created by Heesung Choi on 11/14/24.
//

#include "Span.hpp"
#include <iostream>

void subjectCase();

void randomMore10000();

void nMoreExceptionCase();

void spanNotEnoughExceptionCase();

void addNumberFromContainer();

void addNumberFromRange();

int main() {
	subjectCase();
	randomMore10000();
	nMoreExceptionCase();
	spanNotEnoughExceptionCase();
	addNumberFromContainer();
	addNumberFromRange();

	return 0;
}

void subjectCase() {
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void randomMore10000() {

	Span sp = Span(20000);

	srand(time(NULL));
	for (int i = 0; i < 10000; i++) {
		sp.addNumber(rand());
	}
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void nMoreExceptionCase() {
	Span sp = Span(5);

	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(11);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void spanNotEnoughExceptionCase() {
	Span sp = Span(5);

	try {
		sp.shortestSpan();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void addNumberFromContainer() {
	Span sp = Span(5);

	std::vector<int> vec;
	vec.push_back(6);
	vec.push_back(3);
	vec.push_back(17);
	vec.push_back(9);
	vec.push_back(11);

	sp.addNumber(vec);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void addNumberFromRange() {
	Span sp = Span(5);

	std::vector<int> vec;
	vec.push_back(6);
	vec.push_back(3);
	vec.push_back(17);
	vec.push_back(9);
	vec.push_back(11);

	sp.addNumber(vec.begin(), vec.end());
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}
