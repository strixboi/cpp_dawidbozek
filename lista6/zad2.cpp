#include <iostream>
#include <cmath>
#include <vector>

std::vector<int> F(int n, double x) {
    std::vector<int> cf;
    double number = x;
    double u;
    int a;
    a = (int)number;
    u = 1 / (number - a);
    cf.push_back(a);
    int i = n - 1;
    while (i != 0)
    {
        number = u;
        a = (int)number;
        u = 1 / (number - a);
        cf.push_back(a);
        i--;
    }
    for (int j : cf)
    {
        std::cout<<j<< ",";
    }

    return cf;
}
void getFraction(std::vector<int> a, int size)
{
    double n = 1;
    double d = a[0];
    std::cout<<"\n";
    for(int i = 1; i <= size - 1; i++)
    {
        std::cout << d<< "/" << n<<" "<<(double)(d/n) << "\n";
        double new_d = d*a[i] + n;// nie zwraca poprawnych liczb, pomimo względnie poprawnych obliczen
        n = d;                    // prosiłbym o wytłumaczenie
        d = new_d;                //

    }
    std::cout<<"\n";
}
int main()
{
    getFraction(F(6 ,((1+sqrt(5))/2)), 6);
    getFraction(F(10 ,exp(1)), 10);
}
