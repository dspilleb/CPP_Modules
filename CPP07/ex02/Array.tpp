#include "Array.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

template <typename T> 
Array< T >::Array( void ) : _size(0)
{
	this->_elements = NULL;
}

template <typename T> 
Array< T >::Array(unsigned int set_size) : _size(set_size)
{
	this->_elements = new T[this->_size];
}

template <typename T> 
Array< T >::Array( const Array< T > & src ) : _size(src._size)
{
	this->_elements = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_elements[i] = src._elements[i];

}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

template <typename T> 
Array< T >::~Array( void )
{
	delete[] this->_elements;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

template <typename T> 
Array< T > &				Array< T >::operator=( Array< T > const & rhs )
{
	if ( this != &rhs )
	{
		delete[] this->_elements;
		*this = Array< T >(rhs);
	}
	return *this;
}

template <typename T> 
std::ostream &			operator<<( std::ostream & o, Array< T > const & i )
{
	unsigned int size = i.size();
	for (unsigned int indx; indx < size; indx++)
		o << i[indx] << ((indx != size - 1) ? (" ") : (""));
	o << "\n";
	return o;
}

template <typename T> 
T& Array< T >::operator[](unsigned int index)
{
	if (index >= this->_size)
		throw std::out_of_range("Bad index");
	return (this->_elements[index]);
}


/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

template <typename T> 
unsigned int Array< T >::size( void ) const
{
	return (this->_size);
}

/* ************************************************************************** */