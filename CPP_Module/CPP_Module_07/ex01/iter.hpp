//
// Created by Heesung Choi on 11/14/24.
//

#ifndef CPP_MODULE_ITER_HPP
#define CPP_MODULE_ITER_HPP

#include <iostream>

template<typename T>
void iter(T *array, size_t length, void (*func)(T const &)) {
	for (size_t i = 0; i < length; i++) {
		func(array[i]);
	}
}

template<typename T>
void iter(T const *array, size_t length, void (*func)(T const &)) {
	for (size_t i = 0; i < length; i++) {
		func(array[i]);
	}
}

template<typename T>
void print(T const &value) {
	std::cout << value << " ";
}

#endif //CPP_MODULE_ITER_HPP
