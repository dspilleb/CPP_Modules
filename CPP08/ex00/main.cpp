#include "easyfind.hpp"
#include <list>
#include <vector>
#include <algorithm>

int main ( void )
{

	std::list<int>::const_iterator place;
	std::list<int> numbers;

    numbers.push_back(42);
    numbers.push_back(19);

	int value_to_find = 42; // value in container
	place = easyfind(numbers, value_to_find);
	std::cout << ((place != numbers.end()) ? "found" : "not found") << " => " << value_to_find << std::endl;

	value_to_find = 19; // value in container
	place = easyfind(numbers, value_to_find);
	std::cout << ((place != numbers.end()) ? "found" : "not found") << " => " << value_to_find << std::endl;


	value_to_find = 1000; //value that is not in the container
	place = easyfind(numbers, value_to_find);
	std::cout << ((place != numbers.end()) ? "found" : "not found") << " => " << value_to_find << std::endl;

	return (0);
}