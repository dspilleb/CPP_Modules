#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int value;
		const static int point_bit_position = 8;
	public:
		Fixed ( void );
		Fixed ( Fixed const &ref);
		Fixed & operator=(Fixed const & rhs);
		~Fixed ( void );
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif