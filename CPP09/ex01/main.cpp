#include "RPN.hpp"

int main (int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./RPN <Inverted Polish mathematical expression>" << std::endl;
		return (-1);
	}
	return (calculate_expression(av[1]));
}