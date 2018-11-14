#include <iostream>

class Base {
    public:
        virtual ~Base() {};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base *generate() {
    int i = rand()%3;

    if (i == 0)
	{
		std::cout << "Randomed A" << std::endl;
        return new A();
	}
    else if (i == 1)
	{
		std::cout << "Randomed B" << std::endl;
        return new B();
	}
    else
	{
		std::cout << "Randomed C" << std::endl;
        return new C();
	}
}

void identify_from_pointer(Base * p) {
	if(dynamic_cast<A*>(p))
		std::cout << "Pointers Identity is: A" << std::endl;
	else if(dynamic_cast<B*>(p))
		std::cout << "Pointers Identity is: B" << std::endl;
	else if(dynamic_cast<C*>(p))
		std::cout << "Pointers Identity is: C" << std::endl;
	else
		std::cout << "Pointers Identity is: Dafuck" << std::endl;
}

void identify_from_reference(Base & p) {
	try
	{
		A a = dynamic_cast<A&>(p);
		std::cout << "Reference Identity is: A" << std::endl;
	}
	catch(...)
	{
		try
		{
			B b = dynamic_cast<B&>(p);
			std::cout << "Reference Identity is: B" << std::endl;
		}
		catch(...)
		{
			try
			{
				C c = dynamic_cast<C&>(p);
				std::cout << "Reference Identity is: C" << std::endl;
			}
			catch(...)
			{
				std::cout << "Reference Identity is: Dafuck" << std::endl;
			}
		}
	}
}

int main() {
	srand(time(0));
    Base *base = generate();
    identify_from_pointer(base);
    identify_from_reference(*base);
    return 0;
}
