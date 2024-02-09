#include <iostream>
#include <string.h>
#define MAX 10
using namespace std;

class Program
{
public:
    int data[MAX];
    int index;
    int temp;

    Program() : index(-1), temp(0) {}

    void add()
    {
        if (index == MAX)
        {
            isFull();
        }
        else
        {
            index++;
            data[index] = temp;
        }
    };

    void remove(int indexVal)
    {
        if (index < 0)
        {
            isEmpty();
        }
        else if (indexVal >= 0 && indexVal <= index)
        {
            for (int i = indexVal; i < index; i++)
            {
                for (int j = indexVal; j < index; j++)
                {
                    int tempo = data[i];
                    data[j] = data[j + 1];
                    data[j + 1] = tempo;
                }
            }

            index--;
        }
    };

    void isEmpty()
    {
        if (index < 0)
        {
            cout << "\n ---> The array is empty";
        }
        else
        {
            cout << "\n ---> Array is not empty";
        }
    }

    void isFull()
    {
        if (index == MAX)
        {
            cout << "\n ---> The array is full";
        }
        else
        {
            cout << "\n ---> The array is not full yet";
        }
    }

    void makeEmpty()
    {
        index = -1;
    }

    void traverse()
    {
        if (index < 0)
        {
            cout << "\n ---> The array is empty \n";
        }
        else
        {
            cout << data[temp + 1] << " --> value \n";
        }
    }

    void showArr()
    {
        if (index < 0)
        {
            isEmpty();
        }
        else if (index == 0)
        {
            cout << "\n Current Array : " << data[0];

            for (int i = 0; i < index; i++)
            {
                cout << data[i] << ", ";
            }
            cout << "\n";
        }
        else
        {
            cout << "\n Current Array : ";
            for (int i = 0; i <= index; i++)
            {
                cout << data[i] << ", ";
            }
            cout << "\n";
        }
    }

    ~Program() {}
};

int main()
{
    cout << "===================================================================\n";
    char inp;

    // Ask if user want to create a file
    cout << "\n Do you want to create a data file? \n Y or N: ";
    cin >> inp;

    // Handle the request accroding to the input
    if (inp == 'Y' || inp == 'y')
    {
        Program p1;
        cout << "\nNew file is created. \n";
        // jmp1:
        int reqInp;

        while (reqInp != 7)
        {
            cout << " \n"
                 << "=======================================";
            p1.showArr();

            // Ask what user intend to do in File
            cout << "\n Enter: \n 1 to add \n 2 to delete \n 3 to make list Empty \n "
                 << "4 to check if the list is empty \n "
                 << "5 to check if the list is full \n "
                 << "6 to print the item of specific index \n "
                 << "7 to terminate program \n ";

            cout << "\nInp: ";
            cin >> reqInp;

            // Perform the task accroding to user request
            switch (reqInp)
            {
            case (1): // Add data
                cout << "\nEnter the num you want to add: ";
                cin >> p1.temp;
                p1.add();
                break;

            case (2): // delete data
                cout << "\nEnter the position of data you want to delete: ";
                int x;
                cin >> x;
                p1.remove(x);
                break;

            case (3): // Print the top
                p1.makeEmpty();
                break;

            case (4): // Check if array is empty
                p1.isEmpty();
                break;

            case (5): // Check if array is full
                p1.isFull();
                break;

            case (6): // Print the item of a specific index
                cout << "\nEnter the position of data: ";
                cin >> p1.temp;
                if (p1.index < 0)
                {
                    p1.isEmpty();
                    break;
                }
                else
                {
                    p1.traverse();
                    break;
                }
            case (7): // Terminate
                goto jump1;
                break;

            default:
                cout << "Invalid Input. \n Try again! ";
            }
        }
    }
    else
    {
    jump1:
        cout << "\n Program Terminated. ";
    }
    return 0;
}