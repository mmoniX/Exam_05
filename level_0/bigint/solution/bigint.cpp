#include "bigint.hpp"

bigint::bigint() : digits("0") {}

bigint::bigint(unsigned long long n) : digits(std::to_string(n)) {}

bigint::bigint(std::string digit) : digits(digit) {}

bigint::bigint(const bigint& copy) : digits(copy.digits) {}

bigint& bigint::operator=(const bigint& copy)
{
    if (this != &copy)
    {
        digits = copy.digits;
    }
    return (*this);
}

bigint::~bigint() {}

bigint& bigint::operator++()
{
    *this += bigint(1);
    return *this;
}

bigint bigint::operator++(int)
{
    bigint temp = *this;
    *this += bigint(1);
    return temp;
}

bigint& bigint::operator+=(const bigint& v)
{
    *this = *this + v;
    return *this;
}

bigint bigint::operator+(const bigint& v) const
{
    std::string a = digits;
    std::string b = v.digits;
    while (a.size() < b.size()) a = "0" + a;
    while (b.size() < a.size()) b = "0" + b;

    std::string result;
    int carry = 0;
    for (int i = static_cast<int>(a.size()) - 1; i >= 0; --i)
    {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        carry = sum / 10;
        result = char('0' + sum % 10) + result;
    }
    if (carry)
        result = "1" + result;
    return bigint(result);
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
    if (digits != "0")
        digits.append(n, '0');
    return *this;
}

bigint bigint::operator<<(unsigned int n) const
{
    bigint result(*this);
    result <<= n;
    return result;
}

bigint& bigint::operator>>=(unsigned int n)
{
    if (n >= digits.size())
        digits = "0";
    else
        digits = digits.substr(0, digits.size() - n);
    return *this;
}

bigint bigint::operator>>(unsigned int n) const
{
    bigint result(*this);
    result >>= n;
    return result;
}

bool bigint::operator<(const bigint& v) const
{
    if (digits.size() != v.digits.size())
        return digits.size() < v.digits.size();
    return digits < v.digits;
}

bool bigint::operator>(const bigint& v) const  { return v < *this; }
bool bigint::operator<=(const bigint& v) const { return !(v < *this); }
bool bigint::operator>=(const bigint& v) const { return !(*this < v); }
bool bigint::operator==(const bigint& v) const { return digits == v.digits; }
bool bigint::operator!=(const bigint& v) const { return !(*this == v); }

std::ostream& operator<<(std::ostream& os, const bigint& v)
{
    size_t start = v.digits.find_first_not_of('0');
    os << (start == std::string::npos ? "0" : v.digits.substr(start));
    return os;
}

int toInt(const bigint& v) { return std::stoi(v.digits); }
