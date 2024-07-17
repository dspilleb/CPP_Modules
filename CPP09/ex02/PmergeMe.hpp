#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP
# include <iostream>
# include <vector>
# include <list>
# include <cerrno>
# include <cstdlib>
# include <limits>
# include <iterator>
# include <algorithm> //TODO : remove after testing
# include <cmath>
# include <utility>

# define ERR_ARG "Error: Usage \"./PmergeMe <number_1> <number_2> ... <number_n>\" | <number_n> is a positive integer"
# define ERR_NUM "Error: Argument is not a positive integer => "

bool str_to_int(int &result, const char *str);
bool parse_args(std::vector<int> &v, std::list<int> &l, const int &ac, char ** &av);
std::vector<int> Merge_Insertion_Sort_Vector_util(std::vector<int> v);

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

bool Dichotomic_insertion_Vector(std::vector<int> &v, int value);

#endif 