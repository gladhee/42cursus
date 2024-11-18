//
// Created by HeeSung Choi on 11/18/24.
//

#ifndef CPP_MODULE_MUTANTSTACK_HPP
#define CPP_MODULE_MUTANTSTACK_HPP

#include <algorithm>
#include <stack>


template<class T>
class MutantStack : public std::stack<T> {

public:
	MutantStack() : std::stack<T>() {}

	MutantStack(const MutantStack &other) : std::stack<T>(other) {}

	MutantStack &operator=(const MutantStack &other) {
		if (this == &other) return *this;

		std::stack<T>::operator=(other);

		return *this;
	}

	virtual ~MutantStack() {}

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin() {
		return std::stack<T>::c.begin();
	}

	iterator end() {
		return std::stack<T>::c.end();
	}

};

#endif //CPP_MODULE_MUTANTSTACK_HPP
