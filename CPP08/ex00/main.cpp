#include "easyfind.hpp"
#include <list>
#include <algorithm>

int main ( void )
{

	int value_to_find = 42;
	std::list<int> numbers;

    numbers.push_back(42);
    numbers.push_back(19);

	std::list<int>::const_iterator Algorithm_find;

	Algorithm_find = std::find(numbers.begin(), numbers.end(), value_to_find);
	std::cout << ((Algorithm_find ==  easyfind(numbers, value_to_find) ) ? "Sucess" : "Failure") << std::endl;

	value_to_find = 19;
	Algorithm_find = std::find(numbers.begin(), numbers.end(), value_to_find);
	std::cout << ((Algorithm_find ==  easyfind(numbers, value_to_find) ) ? "Sucess" : "Failure") << std::endl;


	value_to_find = 1000; //value that is not in the container
	Algorithm_find = std::find(numbers.begin(), numbers.end(), value_to_find);
	std::cout << ((Algorithm_find ==  easyfind(numbers, value_to_find) ) ? "Sucess" : "Failure") << std::endl;

	return (0);
}