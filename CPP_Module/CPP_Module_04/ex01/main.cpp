#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main()
{
//    const Animal *meta = new Animal();  // Error: Cannot instantiate abstract class

	// create and fill an array with Animal objects.
	const int n = 10;
	Animal *animals[n];

	// Half of it will be Dog objects and the other half will be Cat objects.
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}

	for (int i = 0; i < n; i++)
		animals[i]->makeSound();

	// At the end of your program execution, loop over this array and delete every Animal.
	for (int i = 0; i < n; i++) {
		// You must delete directly dogs and cats as Animals
		delete animals[i];
	}

	std::cout << "=====================" << std::endl;

	const Cat *i = new Cat();
	i->getBrain()->setIdea(0, "I am a siamese");

	// A copy of a Dog or a Cat must not be shallow.
	const Cat *j = new Cat(*i);
	j->getBrain()->setIdea(0, "I am a persian");

	std::cout << i->getBrain()->getIdea(0) << " " << (i->getBrain()) << std::endl;
	std::cout << j->getBrain()->getIdea(0) << " " << (j->getBrain()) << std::endl;

	delete i;
	delete j;

	std::cout << "=====================" << std::endl;

	Cat *k = new Cat();
	k->getBrain()->setIdea(0, "I am a persian");

	// A copy of a Dog or a Cat must not be shallow.
	Cat *l = new Cat();
	l->getBrain()->setIdea(0, "I am a siamese");
	*l = *k;

	std::cout << k->getBrain()->getIdea(0) << " " << (k->getBrain()) << std::endl;
	std::cout << l->getBrain()->getIdea(0) << " " << (l->getBrain()) << std::endl;

	delete k;
	delete l;

	return 0;
}