#include "Span.hpp"

void assert_distance(unsigned int result, unsigned int expected)
{
	std::cout << ((result == expected) ? GREEN "SUCESS" : RED "FAILURE") << NONE << std::endl;
}

void default_execution(void)
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	assert_distance(sp.shortestSpan(), 2);
	assert_distance(sp.longestSpan(), 14);
}

void test_too_many_values(void)
{
	try
	{
		Span sp = Span(1);
		sp.addNumber(6);
		sp.addNumber(3); // should make an exception
		std::cout << "FAILURE" << std::endl; // should not reach this line
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << GREEN "| SUCCESS" NONE << std::endl;
	}
}

void test_less_than_two_numbers(void)
{
	try
	{
		Span sp = Span(1);
		sp.addNumber(6);
		std::cout << sp.shortestSpan() << std::endl; // should make an exception
		std::cout << "FAILURE" << std::endl; // should not reach this line
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << GREEN "| SUCCESS" NONE << std::endl;
	}

	try
	{
		Span sp = Span(1);
		sp.addNumber(6);
		std::cout << sp.longestSpan() << std::endl; // should make an exception
		std::cout << "FAILURE" << std::endl; // should not reach this line
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << GREEN "| SUCCESS" NONE << std::endl;
	}
}

void test_max_distance(void)
{
	Span sp = Span(2);
	sp.addNumber(std::numeric_limits<int>::max());
	sp.addNumber(std::numeric_limits<int>::min());
	unsigned int expected = std::numeric_limits<int>::max() - std::numeric_limits<int>::min();
	assert_distance(sp.shortestSpan(), expected);
	assert_distance(sp.longestSpan(), expected);
}

void test_a_lot_of_numbers(void)
{
	Span sp = Span(100000);
	std::list<int> numbers;
    for (int i = 1; i <= 100000; ++i) {
        numbers.push_back(i);
    }
	sp.addRange(numbers.begin(), numbers.end());
	assert_distance(sp.shortestSpan(), 1);
	assert_distance(sp.longestSpan(), 100000 - 1);
}

int main()
{

	default_execution();
	test_less_than_two_numbers();
	test_too_many_values();
	test_max_distance();
	test_a_lot_of_numbers();

	return 0;
}
