#include "Fixed.hpp"
#include <cmath>
#include <string>
#include <iostream>

Fixed::Fixed(): value(0) {}

Fixed::Fixed(const Fixed &other) {
	if (this == &other) return;

	*this = other;
}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &other) {
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
	this->value = value << this->fractionalBits;
}

Fixed::Fixed(const float value) {
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

Fixed Fixed::operator+(const Fixed &fixed) const {
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const {
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const {
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const {
	return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);

	this->value++;

	return tmp;
}

Fixed &Fixed::operator++() {
	this->value++;

	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);

	this->value--;

	return tmp;
}

Fixed &Fixed::operator--() {
	this->value--;

	return *this;
}

bool Fixed::operator>(const Fixed &fixed) const {
	return this->toFloat() > fixed.toFloat();
}

bool Fixed::operator<(const Fixed &fixed) const {
	return this->toFloat() < fixed.toFloat();
}

bool Fixed::operator>=(const Fixed &fixed) const {
	return this->toFloat() >= fixed.toFloat();
}

bool Fixed::operator<=(const Fixed &fixed) const {
	return this->toFloat() <= fixed.toFloat();
}

bool Fixed::operator==(const Fixed &fixed) const {
	return this->toFloat() == fixed.toFloat();
}

bool Fixed::operator!=(const Fixed &fixed) const {
	return this->toFloat() != fixed.toFloat();
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return a < b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return a > b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return a > b ? a : b;
}
