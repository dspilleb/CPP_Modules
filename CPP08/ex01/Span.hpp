#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <exception>
# include <algorithm>
# include <list>
# include <cctype>

class Span
{

	public:
		Span(const unsigned int n);
		Span( Span const & src );
		~Span();

		Span &		operator=( Span const & rhs );

		void addNumber(const int number_to_add);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;


	private:
		Span();
		std::list<int> List;
		const unsigned int max_size;

};


#endif /* ************************************************************ SPAN_H */