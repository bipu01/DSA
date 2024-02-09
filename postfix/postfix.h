#ifndef POSTFIX_H
#define POSTFIX_H

#include <iostream>
// using namespace std;
#define MAX 30
#include <string>
#include "stack.h"

class Postfix
{
public:
    std::string qsn;
    int qsnIndex;
    Stack stack1, stack2;
    // Postfix() : qsnIndex(21) {}

    void askEqn();

    void showQsn();
    void showResult();

    int checkPrecidence(char x);
    void checkAndSwap(char charVal);

    void calculate();

    void findPrefix();

    void askForValue();

    friend class Stack;
};

#endif