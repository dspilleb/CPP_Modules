#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base * generate(void)
{
	srand(time(NULL));
	int type = rand() % 3;

	std::cout << "Generated: " << std::flush;
	if (type == 0)
	{
		std::cout << "A" << std::endl;
		return (new A());
	}
	else if (type == 1)
	{
		std::cout << "B" << std::endl;
		return (new B());
	}
	else
	{
		std::cout << "C" << std::endl;
		return (new C());
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != 0)
		std::cout << "Type A !" << std::endl;
	else if (dynamic_cast<B*>(p) != 0)
		std::cout << "Type B !" << std::endl;
	else if (dynamic_cast<C*>(p) != 0)
		std::cout << "Type C !" << std::endl;
	else
		std::cout << "Pointer is Null" << std::endl;
}

void identify(Base& p)
{
	try
	{ 
		dynamic_cast<A&>(p);
		std::cout << "Type A !" << std::endl;
	}
	catch (std::exception& E)
	{
		try
		{
			dynamic_cast<B&>(p);
			std::cout << "Type B !" << std::endl;
		}
		catch(std::exception& E)
		{
			std::cout << "Type C !" << std::endl;
		}
	}
}

int main (void)
{
	srand(static_cast<unsigned int>(time(0)));

	Base *ptr = generate();

	identify(ptr);
	identify(*ptr);

	delete ptr;

	return (0);
}