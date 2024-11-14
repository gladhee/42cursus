//
// Created by Heesung Choi on 11/14/24.
//

#ifndef CPP_MODULE_ARRAY_HPP
#define CPP_MODULE_ARRAY_HPP

#include <stdexcept>


template<class T>
class Array {

private:
	T *array;
	unsigned int size;


public:
	Array() : array(NULL), size(0) {}

	Array(unsigned int n) : size(n) {
		array = new T[n];
	}

	Array(const Array &other) {
		*this = other;
	}

	~Array() {
		delete[] array;
	}

	Array &operator=(const Array &other) {
		if (this == &other) {
			return *this;
		}

		delete[] array;

		size = other.size;

		array = new T[size];

		for (unsigned int i = 0; i < size; ++i) {
			array[i] = other.array[i];
		}

		return *this;
	}

	T &operator[](unsigned int i) {
		if (i >= size) {
			throw std::out_of_range("Out of range");
		}

		return array[i];
	}

	const T &operator[](unsigned int i) const {
		if (i >= size) {
			throw std::out_of_range("Out of range");
		}

		return array[i];
	}

	unsigned int getSize() const {
		return size;
	}

};

#endif //CPP_MODULE_ARRAY_HPP
