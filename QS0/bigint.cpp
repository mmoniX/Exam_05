#include "bigint.hpp"

Bigint::Bigint( void ) : number(0) {}
Bigint::~Bigint () {}
Bigint::Bigint( const int value ) { number = value << bits; }
Bigint::Bigint( const float value ) { number = roundf(value * (1 << bits)); }
Bigint::Bigint( const Bigint &other ) { *this = other; }

Bigint &Bigint::operator=( const Bigint &other )
{
    if(this != &other)
        number = other.getRawBits();
    return *this;
}

float Bigint::toFloat ( void ) const
{
	return (float)number / (1 << bits);
}

int Bigint::toInt( void ) const
{
	return number >> bits; 
}

void Bigint::setRawBits( int const raw )
{
	number = raw;
}
int Bigint::getRawBits( void ) const
{
	return (number);
}

bool Bigint::operator>( const Bigint &other ) const
{
	return number > other.number;
}

bool Bigint::operator<( const Bigint &other ) const
{
	return number < other.number;
}

bool Bigint::operator>=( const Bigint &other ) const
{
	return number >= other.number;
}

bool Bigint::operator<=( const Bigint &other ) const
{
	return number <= other.number;
}

bool Bigint::operator==( const Bigint &other ) const
{
	return number == other.number;
}

bool Bigint::operator!=( const Bigint &other ) const
{
	return number != other.number;
}

Bigint Bigint::operator+( const Bigint &other ) const
{
	Bigint res;
	res.number = this->number + other.number;
	return (res);
}

Bigint &Bigint::operator+=( const Bigint &other )
{
    this->number += other.number;
    return (*this);
}

Bigint &Bigint::operator++()
{
	++this->number;
	return (*this);
}

Bigint Bigint::operator++( int )
{
	Bigint res = *this;
	this->number++;
	return (res);
}

Bigint Bigint::operator<<(int digits) const
{
    Bigint result(*this);
    int multiplier = 1;
    for (int i = 0; i < digits; ++i)
        multiplier *= 10; // power of 10
    result.number *= multiplier;
    return result;
}

Bigint &Bigint::operator<<=(const Bigint &digits)
{
    int shift = digits.toInt();
    int multiplier = 1;
    for (int i = 0; i < shift; ++i)
        multiplier *= 10;
    this->number *= multiplier;
    return (*this);
}

Bigint &Bigint::operator>>=(const Bigint &digits)
{
    int shift = digits.toInt();
    int divisor = 1;
    for (int i = 0; i < shift; ++i)
        divisor *= 10;
    this->number /= divisor;
    return (*this);
}

std::ostream &operator<<(std::ostream &out, const Bigint &obj)
{
	out << obj.getRawBits();
	return (out);
}
