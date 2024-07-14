#include "Span.hpp"
#include <limits>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span(const unsigned int n) : max_size(n)
{
	return;
}

Span::Span() : max_size(0)
{
	return;
}

Span::Span( const Span & src ) : max_size(src.max_size)
{
	this->List = src.List;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
	return;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &				Span::operator=( Span const & rhs )
{
	if ( this != &rhs )
	{
		this->List = rhs.List;
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Span::addNumber(const int number_to_add)
{
	if (this->List.size() >= this->max_size)
		throw std::length_error("Span cannot exceed set size");
	this->List.push_back(number_to_add);
}

unsigned int Span::shortestSpan() const
{
	std::list<int> Copy = this->List;
	std::list<int>::const_iterator start;
	std::list<int>::const_iterator end;
	int current_shortest_distance = std::numeric_limits<int>::max();
	int previous_element = 0;

	if (List.size() <= 1)
		throw std::length_error("Span must contain at least 2 elements to get distance");

	Copy.sort();
	start = Copy.begin();
	end = Copy.end();
	previous_element = *start;

	while (++start != end)
	{
		if (current_shortest_distance > *start - previous_element)
			current_shortest_distance = *start - previous_element;
		previous_element = *start;
	}
	return (current_shortest_distance);
}
unsigned int Span::longestSpan() const
{
	std::list<int>::const_iterator start = this->List.begin();
	std::list<int>::const_iterator end = this->List.end();
	if (List.size() <= 1)
		throw std::length_error("Span must contain at least 2 elements to get distance");


	return (*std::max_element(start, end) - *std::min_element(start, end));
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */