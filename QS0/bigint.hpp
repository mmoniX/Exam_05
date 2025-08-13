#ifndef BIGINT_HPP
# define BIGINT_HPP

# include <iostream>
# include <cmath>

class Bigint
{
    private:
        unsigned long long 	number;
		static const int bits = 0;
    public:
		Bigint( void );
		~Bigint();

		Bigint( const int value );
		Bigint( const float value );
		Bigint( const Bigint &other );
		Bigint &operator=(const Bigint &other);

		float toFloat ( void ) const;
		int toInt( void ) const;
		void setRawBits( int const raw );
		int getRawBits( void ) const;

		bool operator>( const Bigint &other ) const;
		bool operator<( const Bigint &other ) const;
		bool operator>=( const Bigint &other ) const;
		bool operator<=( const Bigint &other ) const;
		bool operator==( const Bigint &other ) const;
		bool operator!=( const Bigint &other ) const;
		
		Bigint operator+( const Bigint &other ) const;
        Bigint &operator+=( const Bigint &other );

		Bigint &operator++();		//++a
		Bigint operator++( int );	//a++

        Bigint operator<<(int digits) const;
        Bigint &operator<<=(const Bigint &digits);
        Bigint &operator>>=(const Bigint &digits);
};
std::ostream &operator<<(std::ostream &out, const Bigint &obj);

#endif