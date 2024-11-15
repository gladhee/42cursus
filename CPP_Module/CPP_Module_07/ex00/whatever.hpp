//
// Created by Heesung Choi on 11/14/24.
//

#ifndef CPP_MODULE_WHATEVER_HPP
#define CPP_MODULE_WHATEVER_HPP

template<typename T>
void swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
T min(T a, T b) {
	return a < b ? a : b;
}

template<typename T>
T max(T a, T b) {
	return a > b ? a : b;
}

#endif //CPP_MODULE_WHATEVER_HPP
