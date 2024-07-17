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

bool parse_args(std::vector<int> &v, std::list<int> &l, const int &ac, char ** &av)
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

// bool Merge_Insertion_Sort_Vector(std::vector<int> v)
// {
	

// }

std::vector<int> Merge_Insertion_Sort_Vector_util(std::vector<int> v)
{
	std::vector<int> v2;
	std::vector<int> v3;

	//1. Make pairs and keep the last element if he exist
	//2. Take the bigger ellements of the pair and call the sort with them => 1
	//3. Sort and insert the smallest element of the smallest pair a the beginning
	//4. Use dichotomic insert for the rest

	if (v.size() > 2)
	{
		for (size_t i = 1; i < v.size(); i += 2)
		{
			if (v[i] > v[i - 1])
			{
				v2.push_back(v[i]);
				v3.push_back(v[i - 1]);
			}
			else
			{
				v2.push_back(v[i - 1]);
				v3.push_back(v[i]);
			}
		}
		if (v.size() % 2)
			v2.push_back(v.back());
		v2 = Merge_Insertion_Sort_Vector_util(v2);
	}
	else
	{
		if (v.size() == 2 && v[0] > v[1])
		{
			int tmp = v[0];
			v[0] = v[1];
			v[1] = tmp;
		}
		return (v);
	}
	print_container(v2.begin(), v2.end());

	size_t min_index = 0;
	for (size_t i = 0; i < v3.size(); i++)
	{
		if (v3[min_index] > v3[i])
			min_index = i;
	}

	v2.insert(v2.begin(), v3[min_index]);
	v3.erase(v3.begin() + min_index);

	for (size_t i = 0; i < v3.size(); i++)
		Dichotomic_insertion_Vector(v2, v3[i]);
	return (v2);

}


bool Dichotomic_insertion_Vector(std::vector<int> &v, int value)
{
	int start, end, middle;

	if (v.empty())
		return (false);

	start = 0;
	end = v.size() - 1;

	while (start <= end)
	{
		middle =  start + ((end - start) / 2);
		// std::cout << "start=" << start << " end=" << end << " middle=" << middle <<  " middle value: " << v[middle] << std::endl;
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
	// std::cout << "value => " << value << " Should be inseted at index => " << start << std::endl;
	return (true);
}
