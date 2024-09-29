#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(): _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	_value = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	_value = static_cast<int>(roundf(value * (1 << _fractionalBits)));
}

Fixed::Fixed(const Fixed &fixed) {
	if (this == &fixed) {
		std::cout << "Self copy constructor called" << std::endl;
		return ;
	}

	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	if (this != &fixed) {
		std::cout << "Copy assignment operator called" << std::endl;
		_value = fixed.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	return _value;
}

void Fixed::setRawBits(const int raw) {
	_value = raw;
}

int Fixed::toInt() const {
	return _value >> _fractionalBits;
}

float Fixed::toFloat() const {
	return static_cast<float>(_value / static_cast<float>(1 << _fractionalBits));
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();

	return out;
}