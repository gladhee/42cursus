#include "Fixed.hpp"
#include <cmath>
#include <string>
#include <iostream>

Fixed::Fixed(): value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;

	if (this == &other) return;

	*this = other;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;

	if (this == &other) return *this;

	this->value = other.getRawBits();

	return *this;
}

int Fixed::getRawBits() const {
	return this->value;
}

void Fixed::setRawBits(int const raw) {
	this->value = raw;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;

	this->value = value << this->fractionalBits;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;

	this->value = static_cast<int>(roundf(value * (1 << this->fractionalBits)));
}

float Fixed::toFloat() const {
	return (static_cast<float>(this->value) / static_cast<float>(1 << this->fractionalBits));
}

int Fixed::toInt() const {
	return this->value >> this->fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();

	return out;
}