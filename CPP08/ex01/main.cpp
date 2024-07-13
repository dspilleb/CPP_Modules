#include "Span.hpp"

int main()
{
		// Default execution
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl; // should be equal to 2
		std::cout << sp.longestSpan() << std::endl; // should be equal to 14

		// Exception too many values
		try
		{
			Span sp = Span(1);
			sp.addNumber(6);
			sp.addNumber(3); // should make an exception
			std::cout << "FAILURE" << std::endl; // should not reach this line
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << " SUCCESS " << std::endl;
		}
		try
		{
			Span sp = Span(1);
			sp.addNumber(6);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << "FAILURE" << std::endl; // should not reach this line
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << " SUCCESS " << std::endl;
		}

		try
		{
			Span sp = Span(1);
			sp.addNumber(6);
			std::cout << sp.longestSpan() << std::endl;
			std::cout << "FAILURE" << std::endl; // should not reach this line
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << " SUCCESS " << std::endl;
		}
	return 0;
}
