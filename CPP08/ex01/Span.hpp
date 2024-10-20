#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <exception>
# include <algorithm>
# include <list>
# include <cctype>
# include <limits>
// # include <ranges> //for linux

# define GREEN "\033[0;32m"
# define ORANGE "\033[1;33m"
# define NONE "\033[0m"
# define BLUE "\033[1;34m"
# define YELLOW "\033[0;33m"
# define RED "\033[1;31m"
# define BWHITE "\033[1;37m"
# define BBLACK "\033[1;30m"
# define MAGENTA "\033[1;35m"

class Span
{

	public:
		Span(const unsigned int n);
		Span( Span const & src );
		~Span();

		Span &		operator=( Span const & rhs );

		void addNumber(const int number_to_add);

		template <typename InputIterator>
		void addRange(InputIterator first, InputIterator last) {
			if (this->max_size < this->List.size() + std::distance(first, last)) {
				throw std::length_error("Span cannot exceed set size");
			}
			this->List.insert(this->List.end(), first, last);
		}

		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;


	private:
		Span();
		std::list<int> List;
		const unsigned int max_size;

};


#endif /* ************************************************************ SPAN_H */