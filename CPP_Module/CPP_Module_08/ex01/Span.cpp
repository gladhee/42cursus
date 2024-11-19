//
// Created by Heesung Choi on 11/14/24.
//

#include "Span.hpp"

Span::Span() : n(0) {}

Span::Span(unsigned int n) : n(n) {}

Span::Span(const Span &other) {
	if (this == &other) return;

	vec.clear();

	n = other.n;

	std::vector<int>::const_iterator it = other.vec.begin();
	while (it != other.vec.end()) {
		vec.push_back(*it);
		it++;
	}

	*this = other;
}

Span &Span::operator=(const Span &other) {
	if (this == &other) return *this;

	n = other.n;

	vec.clear();
	std::vector<int>::const_iterator it = other.vec.begin();
	while (it != other.vec.end()) {
		vec.push_back(*it);
		it++;
	}

	return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
	validateSpanIsFull(1);
	vec.push_back(number);
}

unsigned int Span::shortestSpan() {
	validateEnoughNumbers();

	std::vector<int> sortedVec = vec;
	std::sort(sortedVec.begin(), sortedVec.end());

	int min = INT_MAX;
	std::vector<int>::const_iterator it = sortedVec.begin();
	while (it != sortedVec.end() - 1) {
		int diff = *(it + 1) - *it;
		if (diff < min) {
			min = diff;
		}
		it++;
	}

	return min;
}

unsigned int Span::longestSpan() {
	validateEnoughNumbers();

	std::vector<int> sortedVec = vec;
	std::sort(sortedVec.begin(), sortedVec.end());

	return (sortedVec.back() - sortedVec.front());
}

void Span::validateEnoughNumbers() const {
	if (vec.size() < SPAN_MIN_SIZE) {
		throw Span::NotEnoughNumbersException();
	}
}

const char *Span::IsFullException::what() const throw() {
	return "Span is full.";
}

const char *Span::NotEnoughNumbersException::what() const throw() {
	return "Not enough numbers to calculate span.";
}
