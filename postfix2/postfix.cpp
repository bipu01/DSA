#include <iostream>
using namespace std;
#define MAX 35
#include <string.h>
#include <cstring>

class Stack
{
public:
    char data[MAX];
    int dataIndex;
    int numData[MAX];
    int numDataIndex;
    int openBracketIndex;

    Stack() : dataIndex(-1), openBracketIndex(-1), numDataIndex(-1) {}

    void push(char x)
    {
        dataIndex++;
        data[dataIndex] = x;
    }

    void pushNum(int x)
    {
        numDataIndex++;
        numData[numDataIndex] = x;
    }

    void pop()
    {
        dataIndex--;
    }
    void popNum()
    {
        numDataIndex--;
    }
    char top()
    {
        return data[dataIndex];
    }
    int numTop()
    {
        return numData[numDataIndex];
    }
    int findOpenBracketIndex()
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
    bool isEmpty()
    {
        return dataIndex == -1;
    }
};

class Postfix
{
public:
    string qsn;
    int qsnSize;
    Stack stack1, stack2;

    void askEqn()
    {
        cout << "Enter the qsn: ";
        cin >> qsn;
    }

    void showQsn()
    {
        int size = sizeof(qsn) / sizeof(qsn[0]);
        cout << "\nThe qsn is: \n";
        for (int i = 0; i <= size; i++)
        {
            cout << qsn[i];
        }
        cout << "\n";
    }
    void showResult()
    {
        cout << "\nPostfix: \n";
        for (int i = 0; i <= stack1.dataIndex; i++)
        {
            cout << stack1.data[i];
        }
    }

    int checkPrecidence(char x)
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
    void checkAndSwap(char charVal)
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
        else if (checkPrecidence(stack2.top()) < checkPrecidence(charVal))
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

    void calculate()
    {
        int size = sizeof(qsn) / sizeof(qsn[0]);
        for (int i = 0; i <= size; i++)
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
    void takeValue()
    {
        int numOfNumInPostfixStack = 0;
        for (int a = 0; a <= stack1.dataIndex; a++)
        {
            if (stack1.data[a] >= 'a' && stack1.data[a] <= 'z')
            {
                numOfNumInPostfixStack++;
            }
        }
        // cout << "num of num in stack: " << numOfNumInPostfixStack << endl;
        while (numOfNumInPostfixStack > 0)
        {
            stack2.numDataIndex++;
            cin >> stack2.numData[stack2.numDataIndex];
            numOfNumInPostfixStack--;
        }

        for (int i = 0; i <= stack2.numDataIndex; i++)
        {
            cout << endl
                 << stack2.numData[i] << " ";
        }
    }
    void calculatePostfix()
    {
        int countforInpNumIndex = 0;
        for (int i = 0; i <= stack1.dataIndex; i++)
        {
            if (stack1.data[i] >= 'a' && stack1.data[i] <= 'z')
            {
                stack1.pushNum(stack2.numData[countforInpNumIndex]);
                countforInpNumIndex++;
            }
            else if (stack1.data[i] == '$')
            {
                int temp = 1;
                for (int j = 1; j <= stack1.numData[stack1.numDataIndex]; j++)
                {
                    temp *= stack1.numData[stack1.numDataIndex - 1];
                }
                stack1.popNum();
                stack1.popNum();
                stack1.pushNum(temp);
            }
            else if (stack1.data[i] == '+')
            {
                int temp;
                temp = stack1.numData[stack1.numDataIndex - 1] + stack1.numData[stack1.numDataIndex];
                stack1.popNum();
                stack1.popNum();
                stack1.pushNum(temp);
            }
            else if (stack1.data[i] == '-')
            {
                int temp;
                temp = stack1.numData[stack1.numDataIndex - 1] - stack1.numData[stack1.numDataIndex];
                stack1.popNum();
                stack1.popNum();
                stack1.pushNum(temp);
            }
            else if (stack1.data[i] == '*')
            {
                int temp = 1;
                temp = stack1.numData[stack1.numDataIndex - 1] * stack1.numData[stack1.numDataIndex];
                stack1.popNum();
                stack1.popNum();
                stack1.pushNum(temp);
            }
            else if (stack1.data[i] == '/')
            {
                int temp = 1;
                temp = stack1.numData[stack1.numDataIndex - 1] / stack1.numData[stack1.numDataIndex];
                stack1.popNum();
                stack1.popNum();
                stack1.pushNum(temp);
            }
        }

        cout << "\nPostfix value: " << stack1.numTop();
        // cout << "\nitems in stack2.numData: " << stack2.numData[0] << stack2.numData[1] << stack2.numData[2] << stack2.numData[3] << stack2.numData[4] << endl;
    }

    void findPrefix()
    {
        cout << "\n\nPrefix: \n";
        for (int i = stack1.dataIndex; i >= 0; i--)
        {
            cout << stack1.data[i];
        }
    }

    friend class Stack;
};

int main()
{
    Postfix p1;

    p1.askEqn();
    p1.showQsn();
    p1.calculate();
    p1.showResult();
    p1.findPrefix();

    cout << "\n\nEnter the values of a,b,c,d... ";
    p1.takeValue();
    p1.calculatePostfix();

    return 0;
}