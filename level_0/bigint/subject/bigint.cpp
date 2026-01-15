#include "bigint.hpp"

bigint::bigint() : digits("0") {}

bigint::bigint(unsigned long long n) : digits(std::to_string(n)) {}

bigint::bigint(std::string digits) : digits(digits) {}

bigint::bigint(const bigint& copy) : digits(copy.digits) {}

bigint& bigint::operator=(const bigint& copy)
{
    if (this != &copy)
        digits = copy.digits;
    return *this;
}

bigint::~bigint() {}

std::string bigint::getDigit() const
{
    return digits;
}

bigint& bigint::operator++()
{
    *this = *this + bigint(1);
    return *this;
}

bigint bigint::operator++(int)
{
    bigint temp = *this; 
    *this = *this + bigint(1);
    return temp;
}

bigint& bigint::operator+=(const bigint& v)
{
    *this = *this + v;
    return *this;
}

bigint bigint::operator+(const bigint& v) const
{
    std::string res;
    int x = 0;
    int i = digits.size() - 1;
    int j = v.getDigit().size() - 1;

    while (i >= 0 || j >= 0 || x != 0)
    {
        int sum = x;
        if (i >= 0)
            sum += digits[i--] - '0';
        if (j >= 0)
            sum += v.digits[j--] - '0';
        res.push_back((sum % 10) + '0');
        x = sum / 10;
    }
    std::reverse(res.begin(), res.end());
    return bigint(res);
}

