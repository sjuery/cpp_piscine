#include <iostream>
#include <array>

struct NumberNotFound : public std::exception
{
	const char * what () const throw ()
	{
		return "Parameter wasn't found in container";
	}
};

template <class T>
void easyfind(T, int);
