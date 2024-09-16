#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal {
private:


public:
	Animal();
	Animal(const Animal &copy);
	Animal &operator=(const Animal &copy);
	virtual ~Animal();
	virtual void makeSound() const;
	virtual std::string getType() const;
};


#endif