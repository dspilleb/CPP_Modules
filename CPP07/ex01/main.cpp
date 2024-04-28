# include <iostream>
# include <string>
# include "iter.hpp"

template < typename X>
void print_values(  X &x)
{
	std::cout << x << " "<< std::flush;
}

int main( void ) 
{
	size_t size = 10;
	int *array_int = new int[size];
	float*array_float = new float[size];
	char *array_char = new char[size];

	for (size_t i = 0; i < size; i++)
	{
		array_int[i] = i;
		array_float[i] = i;
		array_char[i] = i + 'a';
	}

	::iter(array_int, size, print_values<int>);
	std::cout << std::endl;
	::iter(array_float, size, print_values<float>);
	std::cout << std::endl;
	::iter(array_char, size, print_values<char>);
	std::cout << std::endl;

	delete array_int;
	delete array_float;
	delete array_char;
	return 0;
}