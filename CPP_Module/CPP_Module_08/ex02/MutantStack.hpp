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
	MutantStack() {};

	MutantStack(const MutantStack &obj) {
		*this = obj;
	};

	MutantStack &operator=(const MutantStack &obj) {
		*this = obj;
		return (*this);
	}

	~MutantStack() {};

	typedef typename MutantStack<T>::stack::container_type::iterator iterator;

	iterator begin(void) {
		return this->c.begin();
	}

	iterator end(void) {
		return this->c.end();
	}

	typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;

	reverse_iterator rbegin(void) {
		return this->c.rbegin();
	}

	reverse_iterator rend(void) {
		return this->c.rend();
	}

	typedef typename MutantStack<T>::stack::container_type::const_iterator const_iterator;

	const_iterator cbegin(void) {
		return this->c.cbegin();
	}

	const_iterator cend(void) {
		return this->c.cend();
	}

	typedef typename MutantStack<T>::stack::container_type::const_reverse_iterator const_reverse_iterator;

	const_iterator crbegin(void) {
		return this->c.crbegin();
	}

	const_iterator crend(void) {
		return this->c.crend();
	}

};

#endif //CPP_MODULE_MUTANTSTACK_HPP
