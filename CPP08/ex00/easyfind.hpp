#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <iterator>

template <typename T>
typename T::const_iterator easyfind(const T & container, const int &find)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), find);
	return (it);
}

#endif /* ******************************************************** EASYFIND_H */