#include <iostream>
using namespace std;
#include <string>
// string fibonacci();
string fibonacci(int prevPrev = 0, int prev = 1, int count = 10, string result = " ")
{
    if (count == 0)
    {
        return result;
    }
    result = result + " " + to_string(prevPrev);
    return fibonacci(prev, prevPrev + prev, --count, result);
}

void printFibo(int a, int b, int n)
{
    if (n == 1)
    {
        cout << a + b << endl;
        return;
    }

    if (a == 0)
        cout << 0 << " " << 1 << " ";

    cout << a + b << " ";

    printFibo(b, a + b, n - 1);
}

int main()
{
    // cout << fibonacci(0, 1, 15, " ");
    printFibo(0, 1, 10);
    return 0;
};
