#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T> 
class Array
{

	public:

		Array( void );
		Array(unsigned int set_size);
		Array( Array< T > const & src );
		~Array( void );

		Array<T> &		operator=( Array<T> const & rhs );
		T& operator[](unsigned int index);
	
		unsigned int size( void ) const;

	private:
		T* _elements;
		unsigned int _size;

};

# include "Array.tpp"

template <typename T> std::ostream &			operator<<( std::ostream & o, Array<T> const & i );

#endif /* *********************************************************** ARRAY_H */