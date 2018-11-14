#include <iostream>
#include <sstream>

class Fixed {
	int _value;
	static const int _fractBits = 8;
public:
    Fixed();
	Fixed(int);
    Fixed(float);
    Fixed(const Fixed&);
	~Fixed();

    Fixed& operator=(const Fixed&);

    int getRawBits();
    void setRawBits(int);
    int toInt() const;
    float toFloat() const;
};

std::ostream& operator <<(std::ostream&, const Fixed&);
