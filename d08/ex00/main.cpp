#include "easyfind.hpp"

template <class T>
void easyfind(T container, int tofind)
{
	try
	{
		for(unsigned long i = 0; i < container.size(); i++)
			if (container[i] == tofind)
			{
				std::cout << tofind << " was first located in node " << i << std::endl;
				return ;
			}
		throw NumberNotFound();
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

}

int main() {
	std::array<int, 3> arr = { {1, 2, 5} };
	easyfind(arr, 5);
	return 0;
}
