#include "scalarConversion.hpp"

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
		ScalarConversion convert(argv[1]);

	    convert.printChar();
	    convert.printInt();
	    convert.printFloat();
	    convert.printDouble();
	}
	else
		std::cout << "Usage: ./convert [Thing to convert]" << std::endl;
    return 0;
}
