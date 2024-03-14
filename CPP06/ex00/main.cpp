#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>

int main(int ac, char **av)
{
    if (ac != 2)
        return ((std::cout << "Wrong numbers of arguments" << std::endl), 1);
    std::stringstream ss;
    double double_test;
    int int_test;
    char char_test;
    float float_test;

    std::string text (av[1]);
    ss << av[1];
    ss >> double_test;


    int_test = static_cast<int> (double_test);
    char_test = static_cast<char> (double_test);
    float_test = static_cast<float> (double_test);

    std::cout << "char: " << std::flush;
    if (int_test < std::numeric_limits<char>::min() || int_test > std::numeric_limits<char>::max() || text.find("nan") != std::string::npos)
        std::cout << "impossible" << std::endl;
    else if (isprint(int_test))
        std::cout <<  "'" << char_test << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;

    std::cout << "int: "  << std::flush;
    if (float_test < std::numeric_limits<int>::min() || float_test > std::numeric_limits<int>::max() || text.find("nan") != std::string::npos)
            std::cout << "impossible" << std::endl;
    else
        std::cout << int_test << std::endl;

    std::cout << "float: " << std::flush;
    if (double_test < std::numeric_limits<float>::min() || double_test > std::numeric_limits<float>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << float_test << 'f' << std::endl;
    std::cout << "double: " << double_test << std::endl;
}