#include <iostream>

template <class T>
void print_given(T *given)
{
	std::cout << *given << std::endl;
}

template <class T>
void iter(T &array, int len, void (*function)(T))
{
	for(int i = 0; i < len; i++)
		function(&array[i]);
}

int main() {
	int numarr[5] = { 1, 2, 3, 4, 5 };
	char chrarr[5] = { 'a', 'b', 'c', 'd', 'e' };
	std::string strarr[5] = { "Hello", "World", "How", "Are", "You?" };
	std::cout << "Num array:" << std::endl;
	::iter(numarr, 5, print_given);
	std::cout << "\nChr array:" << std::endl;
	::iter(chrarr, 5, print_given);
	std::cout << "\nStr array:" << std::endl;
	::iter(strarr, 5, print_given);
	return 0;
}
