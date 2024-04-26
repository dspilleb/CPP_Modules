#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>
#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return ((std::cout << "Wrong numbers of arguments" << std::endl), 1);

    ScalarConverter::convert(av[1]);
}