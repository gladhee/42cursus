#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	if (this != &fixed)
		return;
	*this = fixed;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->_value = fixed.getRawBits();
	return *this;
}

int Fixed::getRawBits() const {
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->_value = value << this->_fractionalBits;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	this->_value = static_cast<int>(roundf(value * (1 << this->_fractionalBits)));
}

float Fixed::toFloat() const {
	return (static_cast<float>(this->_value / (1 << this->_fractionalBits)));
}

int Fixed::toInt() const {
	return (this->_value >> this->_fractionalBits);ㅇㅇㅇ
}

std::ostream &operator<<(std::ostream &os, const Fixed &obj) {
	return os << obj.toFloat();
}