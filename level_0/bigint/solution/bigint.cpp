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

std::string bigint::getDigits() const
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
    int j = v.getDigits().size() - 1;

    while(i >= 0 || j >= 0 || x != 0)
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

bigint& bigint::operator<<=(const bigint& v)
{
    *this <<= static_cast<unsigned int>(toInt(v));
    return *this;
}

bigint& bigint::operator>>=(const bigint& v)
{
    *this >>= static_cast<unsigned int>(toInt(v));
    return *this;
}

bigint bigint::operator<<(const bigint& v) const
{
    return *this << static_cast<unsigned int>(toInt(v));
}

bigint bigint::operator>>(const bigint& v) const
{
    return *this >> static_cast<unsigned int>(toInt(v));
}

bigint& bigint::operator<<=(unsigned int n)
{
    *this = *this << n;
    return *this;
}

bigint& bigint::operator>>=(unsigned int n)
{
    *this = *this >> n;
    return *this;
}

bigint bigint::operator<<(unsigned int n) const
{
    if (*this == bigint(0))
        return *this;
    std::string res = digits;
    res.append(n, '0');
    return bigint(res);
}

bigint bigint::operator>>(unsigned int n) const
{
    if (n >= digits.size())
        return bigint(0);
    std::string res = digits.substr(0, digits.size() - n);
    if (res.empty())
        return bigint(0);
    return bigint(res);
}

bool bigint::operator<(const bigint& v) const
{
    if (digits.size() != v.digits.size())
        return (digits.size() < v.digits.size());
    return digits < v.digits;
}

bool bigint::operator>(const bigint& v) const
{
    if (digits.size() != v.digits.size())
        return (digits.size() > v.digits.size());
    return digits > v.digits;
}

bool bigint::operator<=(const bigint& v) const
{
    return !(*this > v);
}

bool bigint::operator>=(const bigint& v) const
{
    return !(*this < v);
}

bool bigint::operator==(const bigint& v) const
{
    if (digits == v.getDigits())
        return true;
    return false;
}

bool bigint::operator!=(const bigint& v) const
{
    if (digits != v.getDigits())
        return true;
    return false;
}

std::ostream& operator<<(std::ostream& os, const bigint& v)
{
    os << v.getDigits();
    return os;
}

int toInt(const bigint& v)
{
    return std::stoi(v.digits);
}
