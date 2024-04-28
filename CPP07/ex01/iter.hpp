#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template < typename T, typename F>
void iter(T *ptr, const unsigned long size, F &f)
{
	for (size_t i = 0; i < size; i++)
		f(ptr[i]);
}


#endif /* ****************************************************** ITER_H */