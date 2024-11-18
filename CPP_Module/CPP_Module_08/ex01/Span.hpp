//
// Created by Heesung Choi on 11/14/24.
//

#ifndef CPP_MODULE_SPAN_HPP
#define CPP_MODULE_SPAN_HPP

#include <exception>
#include <iostream>
#include <algorithm>
#include <vector>

class Span {

private:
	unsigned int n;
	vector<int> vec;

	Span();

	void validateEnoughNumbers();

	void validateSpanDoesNotSave();

	class SpanDoesNotSaveException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class SpanNotEnoughNumbersException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

public:
	Span(unsigned int n);

	Span(const Span &other);

	Span &operator=(const Span &other);

	~Span();

	template<typename T>
	void addNumber(T number) {
		validateSpanDoesNotSave();
		vec.push_back(number);
	}


	int shortestSpan();

	int longestSpan();


};

#endif //CPP_MODULE_SPAN_HPP
