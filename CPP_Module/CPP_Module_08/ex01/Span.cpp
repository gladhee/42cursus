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

	ohter::iterator it = other.vec.begin();
	while (it != other.vec.end()) {
		vec.push_back(*it);
		it++;
	}


	*this = other;
}

Span &Span::operator=(const Span &other) {
	if (this == &other) return *this;

	this->n = other.n;
	this->vec = other.vec;

	return *this;
}

Span::~Span() {}

int Span::shortestSpan() {
	validateEnoughNumbers();


}

void Span::validateEnoughNumbers() {
	if (this->count < 2) {
		throw Span::SpanNotEnoughNumbersException();
	}
}

void Span::validateSpanDoesNotSave() {
	if (this->vec.size() == this->n) {
		throw Span::SpanDoesNotSaveException();
	}
}

const char *Span::SpanDoesNotSaveException::what() const throw() {
	return "Span is full.";
}

const char *Span::SpanNotEnoughNumbersException::what() const throw() {
	return "Not enough numbers to calculate span.";
}
