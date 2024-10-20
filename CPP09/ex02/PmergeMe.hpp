#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP
# include <iostream>
# include <deque>
# include <list>
# include <cerrno>
# include <cstdlib>
# include <limits>
# include <iterator>
# include <cmath>
# include <utility>
# include <vector>
# include <iomanip>

# define ERR_ARG "Error: Usage \"./PmergeMe <number_1> <number_2> ... <number_n>\" | <number_n> is a positive integer"
# define ERR_NUM "Error: Argument is not a positive integer => "

bool str_to_int(int &result, const char *str);
bool parse_args(std::deque<int> &d, std::vector<int> &v, const int &ac, char ** &av);
std::deque<int> Merge_Insertion_Sort_deque(std::deque<int> d);
std::vector<int> Merge_Insertion_Sort_vector(std::vector<int> v);

template <typename InputIterator>
void print_container(InputIterator begin, InputIterator end)
{
	while (begin != end)
	{
		std::cout << *begin << " " << std::flush;
		begin++;
	}
	std::cout << std::endl;
}

#endif 