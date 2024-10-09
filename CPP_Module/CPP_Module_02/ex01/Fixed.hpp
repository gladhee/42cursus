#pragma once

#include "iostream"

class Fixed {
private:
	int _value;
	static const int _fractionalBits = 8;


public:
	Fixed();
	Fixed(const Fixed &fixed);
	~Fixed();
	Fixed &operator=(const Fixed &fixed);

	Fixed(const int value);
	Fixed(const float value);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
