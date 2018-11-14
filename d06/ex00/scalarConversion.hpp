#ifndef SCALARCONVERSION_HPP
# define SCALARCONVERSION_HPP

#include <iostream>
#include <iomanip>
#include <string>

class ScalarConversion {
	std::string _value;
public:
    ScalarConversion();
    ScalarConversion(const std::string);
    ScalarConversion(const ScalarConversion&);
    ~ScalarConversion();
    ScalarConversion& operator=(ScalarConversion const &);

    void printChar();
    void printInt();
    void printFloat();
    void printDouble();
	std::string getValue() const;
};
#endif
