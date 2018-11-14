#include "scalarConversion.hpp"

ScalarConversion::ScalarConversion(std::string const value) : _value(value) {}

ScalarConversion::ScalarConversion(ScalarConversion const & src) {
    *this = src;
}

ScalarConversion::~ScalarConversion() {}

ScalarConversion& ScalarConversion::operator=(ScalarConversion const & src)
{
	_value = src.getValue();
	return *this;
}

void ScalarConversion::printChar()
{
    try
	{
        if (isprint(static_cast<char>(std::stoi(_value))))
            std::cout << "char : '" << static_cast<char>(std::stoi(_value)) << "'" << std::endl;
        else
            std::cout << "char : Non displayable" << std::endl;
    }
	catch (...)
	{
        std::cout << "char : impossible" << std::endl;
    }
}

void ScalarConversion::printInt()
{
    try
	{
        std::cout << "int : " << std::stoi(_value) << std::endl;
    }
	catch (...) {
        std::cout << "impossible" << std::endl;
    }
}

void ScalarConversion::printFloat()
{
    try
	{
        std::cout << "float : " << std::fixed << std::setprecision(1) << (std::atof(_value.c_str())) << "f" << std::endl;
    }
	catch (...)
	{
        std::cout << "impossible" << std::endl;
    }
}

void ScalarConversion::printDouble()
{
    try
	{
        std::cout << "double : " << std::fixed << std::setprecision(1) << static_cast<double>(std::atof(_value.c_str())) << std::endl;
    }
	catch (...)
	{
        std::cout << "impossible" << std::endl;
    }
}

std::string ScalarConversion::getValue() const
{
	return _value;
}
