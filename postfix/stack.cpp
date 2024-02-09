#include <iostream>
using namespace std;
// #define MAX 30
#include <string.h>
#include "stack.h"

void Stack::push(char x)
{
    dataIndex++;
    data[dataIndex] = x;
}
void Stack::pushNum(int x)
{
    numDataIndex++;
    numData[numDataIndex] = x;
}
void Stack::pop()
{
    dataIndex--;
}
char Stack::top()
{
    return data[dataIndex];
}
int Stack::findOpenBracketIndex()
{
    for (int i = dataIndex; i >= 0; i--)
    {
        if (data[i] == '(')
        {
            return i;
            break;
        }
        else
        {
            continue;
        }
    }
    return -1;
}
bool Stack::isEmpty()
{
    return dataIndex == -1;
}
