#include "PmergeMe.hpp"

#include <cassert>

int main (int ac, char **av)
{
	std::deque<int> v;
	std::list<int> l;

	if (ac <= 1)
	{
		std::cerr << ERR_ARG << std::endl;
		return (-1);
	}
	if (!parse_args(v, l, ac, av))
		return (-1);
	std::cout << "Before:  " << std::flush;
	print_container(v.begin(), v.end());
	v = Merge_Insertion_Sort_deque(v);
	std::cout << "After:  " << std::flush;
	print_container(v.begin(), v.end());


	return (0);

}