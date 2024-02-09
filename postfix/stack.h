#ifndef STACK_H
#define STACK_H

#define MAX 30
// using namespace std;

class Stack
{
public:
    char data[MAX];
    int dataIndex;
    int numData[MAX];
    int numDataIndex;
    int openBracketIndex;

    Stack() : dataIndex(-1), openBracketIndex(-1), numDataIndex(-1) {}

    void push(char x);
    void pushNum(int x);
    void pop();
    char top();
    int findOpenBracketIndex();
    bool isEmpty();
};

#endif