#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
private:
	int _value;
	static const int _fractionalBits = 8;


public:
	Fixed();

	explicit Fixed(const int value);
	explicit Fixed(const float value);
	Fixed(const Fixed &fixed);
	~Fixed();
	Fixed &operator=(const Fixed &fixed);

	float toFloat(void) const;
	int toInt(void) const;

};


#endif