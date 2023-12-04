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
		bool operator>(Fixed const &second) const;
		bool operator<(Fixed const &second) const;
		bool operator>=(Fixed const &second) const;
		bool operator<=(Fixed const &second) const;
		bool operator==(Fixed const &second) const;
		bool operator!=(Fixed const &second) const;
		Fixed operator+(Fixed const &second) const;
		Fixed operator-(Fixed const &second) const;
		Fixed operator*(Fixed const &second) const;
		Fixed operator/(Fixed const &second) const;
		Fixed& operator++();
		Fixed operator++( int );
		Fixed& operator--();
		Fixed operator--( int );
		static Fixed max(Fixed const &first, Fixed const &second);
		static Fixed& max(Fixed &first, Fixed &second);
		static Fixed min(Fixed const &first, Fixed const &second);
		static Fixed& min(Fixed &first, Fixed &second);
	};

std::ostream& operator<<(std::ostream &os, Fixed const &ref);
#endif