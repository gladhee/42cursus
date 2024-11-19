//
// Created by Heesung Choi on 11/19/24.
//

#include "Base.hpp"

int main() {
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;
	return 0;
}