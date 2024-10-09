#pragma once

class Fixed {
private:
	int value;
	static const int fractionalBits = 8;


public:
	Fixed();
	Fixed(const Fixed &other);
	~Fixed();
	Fixed &operator=(const Fixed &other);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	
};