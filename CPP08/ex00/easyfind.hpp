#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <iterator>

template <typename T>
typename T::const_iterator easyfind(const T & container, const int &find)
{
	typename T::const_iterator it;
	typename T::const_iterator ite = container.end();
	for (it = container.begin(); it != ite; ++it)
		if (*it == find)
			return (it);
	return (ite);
}

#endif /* ******************************************************** EASYFIND_H */