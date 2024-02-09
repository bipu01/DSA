#include <iostream>
#define MAX 10
using namespace std;

class Stack
{
public:
    int arr[MAX];
    int index;

    Stack() : index(-1) {}

    void push(int x)
    {
        index++;
        arr[index] = x;
    }

    void pop()
    {
        index--;
    }

    void top()
    {
        cout << "Top: " << arr[index] << endl;
    }
    void makeEmpty()
    {
        index = -1;
    }
    bool isEmpty()
    {
        if (index < 0)
        {
            cout << "The stack is empty\n";
            return 1;
        }
        return 0;
    }
    bool isFull()
    {
        if (index == MAX - 1)
        {
            cout << "The stack is FUll\n";
            return 1;
        }
        return 0;
    }
    void traverse(int x)
    {
        if (isEmpty())
        {
            cout << "Stack is Empty\n";
        }
        else
        {
            cout << "value at " << x << "is : " << arr[x - 1] << endl;
        }
    }
    void menuControl()
    {
        int reqInp;

        while (reqInp != 7)
        {

            // Ask what user intend to do in File
            cout << "\n Enter: \n 1 to print the top item\n"
                 << " 2 to push item to stack \n "
                 << "3 to pop the item from stack \n "
                 << "4 to check if the Stack is empty \n "
                 << "5 to check if the Stack is full \n "
                 << "6 to print the item from place 1-11 \n "
                 << "7 to terminate program \n ";

            cout << "\nInp: ";
            cin >> reqInp;

            // Perform the task accroding to user request
            switch (reqInp)
            {
            case (1): // Top item
                if (isEmpty())
                {
                    cout << "The stack is Empty\n";
                    break;
                }
                else
                {
                    top();
                    break;
                }

            case (2): // Push
                cout << "\nEnter the value you want to push: ";
                int x;
                cin >> x;
                push(x);
                break;

            case (3): // Pop
                pop();
                break;

            case (4): // Check if array is empty
                if (isEmpty())
                {
                    cout << "Empty\n";
                    break;
                }
                else
                {
                    cout << "Not Empty\n";
                    break;
                }

            case (5): // Check if array is full
                if (isFull())
                {
                    cout << "Full\n";
                    break;
                }
                else
                {
                    cout << "Not Full\n";
                    break;
                }

            case (6): // traverse
                cout << "\nEnter the position of data from 1-11: ";
                int y;
                cin >> y;

                traverse(y);
                break;
            case (7): // Terminate
                break;
            default:
                cout << "Invalid Input. \n Try again! ";
            }
        }
    }
    ~Stack() {}
};

int main()
{
    Stack s1;
    s1.menuControl();
    return 0;
};