#include <iostream>
#include "cmath"
class Fraction
{
    int64_t gcd(int64_t a, int64_t b) { return b == 0 ? a : gcd(b, a % b); }
    int64_t n, d;
public:
    Fraction(int n, int d = 1) : n(n/gcd(n, d)), d(d/gcd(n, d)) { }
    int64_t num() const { return n; }
    int64_t den() const { return d; }
    Fraction& operator*=(const Fraction& rhs)
    {
        int new_n = n * rhs.n/gcd(n * rhs.n, d * rhs.d);
        d = d * rhs.d/gcd(n * rhs.n, d * rhs.d);
        n = new_n;
        return *this;
    }
    Fraction& operator+=(const Fraction& rhs)
    {
        int64_t n_new = (n* rhs.d + rhs.n * d);
        int64_t d_new = d* rhs.d;
        n = n_new / gcd(n_new,d_new);
        d = d_new / gcd(n_new,d_new);
        return *this;
    }
    Fraction operator/=(const Fraction& rhs)
    {
        int64_t n_new = n * rhs.d/gcd(n*rhs.d,d*rhs.n);
        n = n_new;
        d = d*rhs.n/ gcd(n * rhs.d, d*rhs.n);
        return *this;
    }
    double to_double() const
    {
        return (double)n / d;
    }
    Fraction operator-=(const Fraction& rhs)
    {
        int64_t n_new = (n*rhs.d - rhs.n *d);
        int64_t d_new = d*rhs.d;
        n = n_new/gcd(n_new, d_new);
        d = d_new/ gcd(n_new, d_new);
        return *this;
    }
};
std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
    return out << f.num() << '/' << f.den();
}
bool operator==(const Fraction& lhs, const Fraction& rhs)
{
    return lhs.num() == rhs.num() && lhs.den() == rhs.den();
}
bool operator!=(const Fraction& lhs, const Fraction& rhs)
{
    return !(lhs == rhs);
}
Fraction operator*(Fraction lhs, const Fraction& rhs)
{
    return lhs *= rhs;
}
Fraction operator+(Fraction lhs, const Fraction& rhs)
{
    return lhs += rhs;
}
Fraction operator-(Fraction lhs, const Fraction& rhs )
{
    return lhs -= rhs;
}
Fraction operator/(Fraction lhs, const Fraction& rhs)
{
    return lhs /= rhs;
}
void sum_i()
{
    std::cout<<"Suma i: "<<'\n';
    Fraction x(0);
    for(int i=1;i<=100;i++)
    {
        Fraction tmp(1,i*(i+1));
        x +=tmp;
        std::cout<<"i = "<<i<<", "<<tmp<<"     "<<tmp.to_double()<<'\n';
    }
}
void sum_ii()
{
    std::cout<<"Suma ii: "<<'\n';
    Fraction x(0);
    for(int i=1;i<=20;i++)
    {
        Fraction tmp(1, i); //zadanie poprawilem, zeby wygladalo jak w przykladzie z listy
//      Fraction tmp(pow(-1,i+1), i);
        x +=tmp;
        std::cout<<"ii = "<<i<<", "<< tmp<<"    "<<tmp.to_double()<<'\n';
    }
}
void sum_iii()
{
    std::cout<<"Suma iii: "<<'\n';
    Fraction x(0);
    for(int i=1;i<=15;i++)
    {
        Fraction tmp(1,pow(2,i)*i);
        x +=tmp;
        std::cout<<"iii = "<<i<<", "<< tmp<<"    "<<tmp.to_double()<<'\n';
    }
}


int main()
{
    Fraction f1(3, 8), f2(1, 2), f3(10, 2);
    std::cout << f1 << " * " << f2 << " = " << f1 * f2 << '\n'
              << f2 << " * " << f3 << " = " << f2 * f3 << '\n'
              << 2 << " * " << f1 << " = " << 2 * f1 << '\n'
              << f2 << " + " << f1 << " = " << f2+ f1 << '\n'
              << f2 << " - " << f3 << " = " << f2 - f3 << '\n'
              << f2 << " / " << f1 << " = " << f2 / f1 << '\n';

    sum_i();
    sum_ii();
    sum_iii();
}