// #include <iostream>
// using namespace std;
// #define MAX 30
// #include <string.h>
#include "stack.h"
#include "postfix.h"

int main()
{
    Postfix p1;

    p1.askEqn();
    p1.showQsn();
    p1.calculate();
    p1.showResult();
    p1.findPrefix();

    return 0;
}