#include <iostream>
#include <sstream>

int main(void)
{
    std::stringstream ss;

    ss << "2264564545456456465465465456456";
    int test;

    ss >> test;
    std::cout << test << std::endl;
}