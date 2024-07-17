#include "PmergeMe.hpp"

bool str_to_int(int &result, const char *str)
{
	long l;
	char *end;
	errno = 0;

	l = std::strtol(str, &end, 0);
	if ((errno == ERANGE && l == std::numeric_limits<long>::max()) || l > std::numeric_limits<int>::max())
		return (false);
	else if (l < 0)
		return (false);
	else if (!*str || *end != '\0')
		return (false);
	result = static_cast<int>(l);

	return (true);
}

bool parse_args(std::deque<int> &v, std::list<int> &l, const int &ac, char ** &av)
{
	int result;

	for (int i = 1; i < ac; i++)
	{
		if (str_to_int(result, av[i]))
		{
			v.push_back(result); //? Check doublons ?
			l.push_back(result);
		}
		else
		{
			std::cerr << ERR_NUM << "'" << av[i] << "'" << std::endl;
			return (false);
		}
	}
	return (true);
}

static bool Dichotomic_insertion_deque(std::deque<int> &v, int value)
{
	int start, end, middle;

	if (v.empty())
		return (false);

	start = 0;
	end = v.size() - 1;

	while (start <= end)
	{
		middle =  start + ((end - start) / 2);
		if (value < v[middle])
		{
			end = middle - 1;
		}
		else
		{
			start = middle + 1;
		}
	}

	v.insert(v.begin() + start, value);
	return (true);
}

std::deque<int> Merge_Insertion_Sort_deque(std::deque<int> v)
{
	std::deque<int> sorted_deque;
	std::deque<int> tmp;

	if (v.size() > 2)
	{
		//1. Make pairs and keep the last element if he exist
		//2. Take the bigger ellements of the pair and call the sort with them => 1
		for (size_t i = 1; i < v.size(); i += 2)
		{
			if (v[i] > v[i - 1])
			{
				sorted_deque.push_back(v[i]);
				tmp.push_back(v[i - 1]);
			}
			else
			{
				sorted_deque.push_back(v[i - 1]);
				tmp.push_back(v[i]);
			}
		}
		if (v.size() % 2)
		{
			tmp.push_back(v.back());
		}
		sorted_deque = Merge_Insertion_Sort_deque(sorted_deque);

		 //3. insert the smallest element of the unsorted pairs at the beginning
		size_t min_index = 0;
		for (size_t i = 0; i < tmp.size(); i++)
		{
			if (tmp[min_index] > tmp[i])
				min_index = i;
		}
		// std::cout << "smallest => " << tmp[min_index] << std::endl; //? Debug
		sorted_deque.push_front(tmp[min_index]);
		tmp.erase(tmp.begin() + min_index);

		//  print_container(sorted_deque.begin(), sorted_deque.end()); //? Debug

		//4. Use dichotomic insert for the rest
		for (size_t i = 0; i < tmp.size(); i++)
			Dichotomic_insertion_deque(sorted_deque, tmp[i]);
	}

	else // Contains one or two unsorted elements, sort them
	{
		if (v.size() == 2 && v[0] > v[1])
			std::swap(v[0], v[1]);
		return (v);
	}

	return (sorted_deque);

}

