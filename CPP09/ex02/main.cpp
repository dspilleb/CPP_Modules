#include "PmergeMe.hpp"

#include <sys/time.h>
#include <iostream>

unsigned long long getMicroseconds() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000ULL + tv.tv_usec;
}

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

	std::cout << "Before:  " << std::flush;
	print_container(d.begin(), d.end());

    unsigned long long start = getMicroseconds();
	d = Merge_Insertion_Sort_deque(d);
    unsigned long long end = getMicroseconds();
	double elapsed = end - start;

	std::cout << "After:   " << std::flush;
	print_container(d.begin(), d.end());

	std::cout << "Time to process a range of " << v.size() << " elements with std::deque : " << std::flush;
    std::cout << std::fixed << std::setprecision(5) << elapsed << " us" << std::endl;

	start = getMicroseconds();
	v = Merge_Insertion_Sort_vector(v);
	end = getMicroseconds();
	elapsed = end - start;
	std::cout << "Time to process a range of " << v.size() << " elements with std::vector : " << std::flush;
    std::cout << std::fixed << std::setprecision(5) << elapsed << " us" << std::endl;
	return (0);

}