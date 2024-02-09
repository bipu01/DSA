#include <iostream>
using namespace std;
#define MAX 30
#include <string>
#include "stack.h"
#include "postfix.h"

void Postfix::askEqn()
{
    cout << "Enter 'capital E' to confirm finish at any time\n";
    cout << "Enter the qsn: ";
    cin >> qsn;
}

void Postfix::showQsn()
{
    cout << "\nThe qsn is: \n";
    for (int i = 0; i <= qsnIndex; i++)
    {
        cout << qsn[i];
    }
    cout << "\n";
}
void Postfix::showResult()
{
    cout << "\nPostfix: \n";
    for (int i = 0; i <= stack1.dataIndex; i++)
    {
        cout << stack1.data[i];
    }
}

int Postfix::checkPrecidence(char x)
{
    switch (x)
    {
    case '$':
        return 3;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '+':
    case '-':
        return 1;
        break;
    default:
        return -1;
        break;
    }
}
void Postfix::checkAndSwap(char charVal)
{

    int selfPrec = checkPrecidence(charVal);

    if (stack2.isEmpty())
    {
        stack2.push(charVal);
    }
    else if (checkPrecidence(stack2.top()) < 0)
    {
        stack2.push(charVal);
    }
    else if (checkPrecidence(stack2.top()) <= checkPrecidence(charVal))
    {
        stack2.push(charVal);
    }
    else
    {
        stack1.push(stack2.top());
        stack2.pop();
        stack2.push(charVal);
    }
}

void Postfix::calculate()
{
    for (int i = 0; i <= qsnIndex; i++)
    {
        if (qsn[i] >= 'a' && qsn[i] <= 'z')
        {
            stack1.push(qsn[i]);
        }
        else if (qsn[i] == '(')
        {
            stack2.push(qsn[i]);
        }
        else if (qsn[i] == '$')
        {
            checkAndSwap(qsn[i]);
        }
        else if (qsn[i] == '*' || qsn[i] == '/')
        {
            checkAndSwap(qsn[i]);
        }
        else if (qsn[i] == '+' || qsn[i] == '-')
        {
            checkAndSwap(qsn[i]);
        }
        else if (qsn[i] == ')')
        {
            int bracInd = stack2.findOpenBracketIndex();
            if (bracInd >= 0)
            {
                int j = stack2.dataIndex;
                while (j >= bracInd)
                {
                    if (stack2.data[j] == '(')
                    {
                        stack2.pop();
                        break;
                    }
                    else
                    {
                        stack1.push(stack2.data[j]);
                        stack2.pop();
                        j--;
                    }
                }
            }
        }
    }

    if (!stack2.isEmpty())
    {
        for (int i = stack2.dataIndex; i >= 0; i--)
        {
            stack1.push(stack2.data[i]);
        }
    }
}

void Postfix::findPrefix()
{
    cout << "\n\nPrefix: \n";
    for (int i = stack1.dataIndex; i >= 0; i--)
    {
        cout << stack1.data[i];
    }
}

void Postfix::askForValue()
{
    cout << "Enter the value of a";
}
