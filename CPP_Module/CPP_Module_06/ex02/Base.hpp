//
// Created by Heesung Choi on 11/19/24.
//

#ifndef CPP_MODULE_BASE_HPP
#define CPP_MODULE_BASE_HPP


class Base {

public:
	virtual ~Base() {};

};

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

#endif //CPP_MODULE_BASE_HPP
