//
// Created by Heesung Choi on 11/14/24.
//

#ifndef CPP_MODULE_EASYFIND_HPP
#define CPP_MODULE_EASYFIND_HPP

#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int value) {
	return std::find(container.begin(), container.end(), value);
}

#endif //CPP_MODULE_EASYFIND_HPP
