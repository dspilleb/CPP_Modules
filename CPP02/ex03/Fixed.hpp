#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int value;
		const static int point_bit_position = 8;
	public:
		Fixed ( void );
		Fixed ( Fixed const &ref);
		Fixed (const int init_val);
		Fixed (const float init_val);
		Fixed & operator=(Fixed const & rhs);
		~Fixed ( void );
		int getRawBits( void ) const;
		int get_point_bit_position( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		// Ajouter min/max
	};

std::ostream& operator<<(std::ostream &os, Fixed const &ref);

int operator>(Fixed const &first, Fixed const &second);
int operator<(Fixed const &first, Fixed const &second);
int operator>=(Fixed const &first, Fixed const &second);
int operator<=(Fixed const &first, Fixed const &second);
int operator==(Fixed const &first, Fixed const &second);
int operator!=(Fixed const &first, Fixed const &second);

// +
Fixed operator+(Fixed const &first, Fixed const &second);
// -
Fixed operator-(Fixed const &first, Fixed const &second);
// *
Fixed operator*(Fixed const &first, Fixed const &second);
// /
Fixed operator/(Fixed const &first, Fixed const &second);

// pré-incrémentation
//int operator++(Fixed const &first, Fixed const &second);
// post-incrémentation
// pré-décrémentation
// post-décrémentation
#endif