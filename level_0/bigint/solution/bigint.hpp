#pragma once
#include <string>
#include <iostream>
#include <algorithm>

class bigint
{
    private:
        std::string digits;
    public:
        bigint();
        bigint(unsigned long long n);
        bigint(std::string digits);
        bigint(const bigint& copy);
        bigint& operator=(const bigint& copy);
        ~bigint();

        std::string getDigits() const;

        bigint& operator++();
        bigint operator++(int);

        bigint& operator+=(const bigint& v);
        bigint operator+(const bigint& v) const;

        bigint& operator<<=(const bigint& v);
        bigint& operator>>=(const bigint& v);
        bigint operator<<(const bigint& v) const;
        bigint operator>>(const bigint& v) const;

        bigint& operator<<=(unsigned int n);
        bigint& operator>>=(unsigned int n);
        bigint operator<<(unsigned int n) const;
        bigint operator>>(unsigned int n) const;

        bool operator<(const bigint& v) const;
        bool operator>(const bigint& v) const;
        bool operator<=(const bigint& v) const;
        bool operator>=(const bigint& v) const;
        bool operator==(const bigint& v) const;
        bool operator!=(const bigint& v) const;

        friend std::ostream& operator<<(std::ostream& os, const bigint& v);
        friend int toInt(const bigint& v);
};
