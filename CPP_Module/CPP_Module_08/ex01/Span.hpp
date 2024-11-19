//
// Created by Heesung Choi on 11/14/24.
//

#ifndef CPP_MODULE_SPAN_HPP
#define CPP_MODULE_SPAN_HPP

#include <algorithm>
#include <vector>

class Span {

	static const int SPAN_MIN_SIZE = 2;

private:
	unsigned int n;
	std::vector<int> vec;

	Span();

	void validateEnoughNumbers() const;

	template<typename T>
	void validateSpanIsFull(T number) const {
		if (vec.size() + number > n) {
			throw IsFullException();
		}
	}

	class IsFullException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class NotEnoughNumbersException : public std::exception {
	public:
		virtual const char *what() const throw();
	};


public:
	Span(unsigned int n);

	Span(const Span &other);

	Span &operator=(const Span &other);

	~Span();

	void addNumber(int number);

	template<typename T>
	void addNumber(T &container) {
		validateSpanIsFull(container.size());
		typename T::iterator it = container.begin();
		while (it != container.end()) {
			vec.push_back(*it);
			it++;
		}
	}

	template<typename T>
	void addNumber(T begin, T end) {
		validateSpanIsFull(end - begin);
		while (begin != end) {
			vec.push_back(*begin);
			begin++;
		}
	}

	unsigned int shortestSpan();

	unsigned int longestSpan();


};

#endif //CPP_MODULE_SPAN_HPP
