#include "PmergeMe.hpp"

#include <cassert>

int main (int ac, char **av)
{
	std::deque<int> d;
	std::vector<int> v;

	if (ac <= 1)
	{
		std::cerr << ERR_ARG << std::endl;
		return (-1);
	}
	if (!parse_args(d, v, ac, av))
		return (-1);
	std::cout << std::fixed << std::setprecision(10);

	std::cout << "Deque => Before:  " << std::flush;
	print_container(d.begin(), d.end());

	clock_t start = clock();
	d = Merge_Insertion_Sort_deque(d);
	clock_t end = clock();

	std::cout << "After:  " << std::flush;

	print_container(d.begin(), d.end());
	std::cout << "Time to process a range of " << d.size() << " elements with std::deque : " << static_cast<double>(end - start) / (CLOCKS_PER_SEC * 1e6) <<" us" << std::endl;

	start = clock();
	v = Merge_Insertion_Sort_vector(v);
	end = clock();
	std::cout << "Time to process a range of " << d.size() << " elements with std::deque : " << static_cast<double>(end - start) / (CLOCKS_PER_SEC * 1e6) <<" us" << std::endl;

	return (0);

}