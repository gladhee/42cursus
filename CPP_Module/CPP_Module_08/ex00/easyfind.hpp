//
// Created by Heesung Choi on 11/14/24.
//

#ifndef CPP_MODULE_EASYFIND_HPP
#define CPP_MODULE_EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &container, int value) {
	typename T::iterator it =  std::find(container.begin(), container.end(), value);

	if (it == container.end()) {
		throw std::invalid_argument("Value not found.");
	}

	return it;
}

template<typename T>
typename T::iterator easyfind(T const &container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);

	if (it == container.end()) {
		throw std::invalid_argument("Value not found.");
	}

	return it;
}

#endif //CPP_MODULE_EASYFIND_HPP
