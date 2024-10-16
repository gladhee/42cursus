#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

//void leaks(void) {
//	system("leaks abstract");
//}

int main()
{
//	atexit(leaks);
//	 const Animal *a = new Animal(); // can be instantiated

	const int n = 10;
	Animal *animals[n];

	for (int i = 0; i < n; i++) {
		if (i & 1)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}

	for (int i = 0; i < n; i++)
		animals[i]->makeSound();

	for (int i = 0; i < n; i++) {
		delete animals[i];
	}

	std::cout << "\n------------------\n" << std::endl;

	const Cat *i = new Cat();
	i->getBrain()->setIdea(0, "I'm a Dachshund");

	const Cat *j = new Cat(*i);
	j->getBrain()->setIdea(0, "I'm a persian");

	std::cout << i->getBrain()->getIdea(1000000) << " " << (i->getBrain()) << std::endl;
	std::cout << j->getBrain()->getIdea(0) << " " << (j->getBrain()) << std::endl;

	delete i;
	delete j;

	std::cout << "\n------------------\n" << std::endl;

	Cat *k = new Cat();
	k->getBrain()->setIdea(0, "I'm a Dachshund");

	Cat *l = new Cat();
	l->getBrain()->setIdea(0, "I'm a persian");
	*l = *k;

	std::cout << k->getBrain()->getIdea(0) << " " << (k->getBrain()) << std::endl;
	std::cout << l->getBrain()->getIdea(0) << " " << (l->getBrain()) << std::endl;

	delete k;
	delete l;

	return 0;
}