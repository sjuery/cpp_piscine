#include <iostream>

class Fixed {
	int _value;
	static const int _fractBits = 8;
public:
	Fixed(void);
	Fixed(Fixed& src);
	~Fixed();

	Fixed& operator=(Fixed& src);
	int getRawBits(void);
	void setRawBits(int const raw);
};
