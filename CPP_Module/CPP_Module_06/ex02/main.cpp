//
// Created by Heesung Choi on 11/19/24.
//

#include "Base.hpp"
#include <iostream>

int main() {
	srand(time(0));

	std::cout << "Test 1" << std::endl;

	Base *base = generate();
	identify(base);
	identify(*base);

	std::cout << "\nTest 2" << std::endl	;

	Base *base2 = generate();
	identify(base2);
	identify(*base2);

	std::cout << "\nTest 3" << std::endl;

	Base *base3 = generate();
	identify(base3);
	identify(*base3);

	std::cout << "\nTest 4" << std::endl;

	Base *base4 = generate();
	identify(base4);
	identify(*base4);

	delete base;
	delete base2;
	delete base3;
	delete base4;

	return 0;
}