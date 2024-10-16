#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

//void leaks(void) {
//	system("leaks animal");
//}

int	main(void) {

//	atexit(leaks);

	const Animal* meta = new Animal();
	const Animal* dog	= new Dog();
	const Animal* cat	= new Cat();

	std::cout << std::endl;

	std::cout << "Type is " << meta->getType() << std::endl;
	std::cout << "Type is " << cat->getType() << std::endl;
	std::cout << "Type is " << dog->getType() << std::endl;

	std::cout << std::endl;

	meta->makeSound();
	dog->makeSound();
	cat->makeSound();

	std::cout << std::endl;

	delete meta;
	delete dog;
	delete cat;

	std::cout << "\n------------------\n" << std::endl;

	const	WrongAnimal*	test = new WrongAnimal();
	const	WrongAnimal*	testCat = new WrongCat();

	std::cout << std::endl;

	std::cout << "Type is " << test->getType() << std::endl;
	std::cout << "Type is " << testCat->getType() << std::endl;

	std::cout << std::endl;

	test->makeSound();
	testCat->makeSound();

	std::cout << std::endl;

	delete test;
	delete testCat;

	return (0);
}