#include <iostream>
using namespace std;

int gcd(int num1, int num2)
{

    if (num1 % num2 == 0)
    {
        return num2;
    }
    return gcd(num1, num2 - 1);
}

int main()
{
    cout << gcd(50, 30);
    return 0;
};
