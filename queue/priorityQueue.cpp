#include <iostream>
using namespace std;
#define MAX 10

class PriorityQueue
{
public:
    int data[MAX], front, rear, leastSignificantNum, leastSignificantNumIndex;

    PriorityQueue() : front(-1), rear(-1), leastSignificantNum(9999) {}

    void emptyQueue()
    {
        rear = -1;
        front = -1;
    }

    bool isFull()
    {
        if (rear == MAX - 1)
        {
            cout << "Queue is Full" << endl;
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        if (rear < 0 && front < 0)
        {
            return true;
        }
        return false;
    }

    void enque(int temp)
    {
        if (isFull())
        {
            cout << "Queue is full";
        }
        rear++;
        data[rear] = temp;
    }

    void deque()
    {
        if (isEmpty())
        {
            cout << isEmpty();
        }
        else
        {
            leastSignificantNum = 9999;
            leastSignificantNumIndex = -1;
            for (int i = front; i <= rear; i++)
            {
                if (data[i] <= leastSignificantNum)
                {
                    leastSignificantNum = data[i];
                    leastSignificantNumIndex = i;
                }
            }

            int tempo = data[front + 1];
            data[front] = data[leastSignificantNumIndex];
            data[leastSignificantNumIndex] = tempo;
            front++;
        }
    }

    void viewQueue()
    {
        if (isEmpty())
        {
            cout << isEmpty();
        }
        else
        {
            cout << "[ ";
            for (int i = front + 1; i <= rear; i++)
            {
                cout << " " << data[i];
            }
            cout << " ]\n";
        }
    }

    void menuDriven()
    {

        int x;
        while (x != 5)
        {
            cout << "\nPress: \n";
            cout << "1 to Enque \n";
            cout << "2 to deque \n";
            cout << "3 to view Queue \n";
            cout << "4 to empty the Queue\n";
            cout << "5 to Quit the program \n";
            viewQueue();
            cout << endl;
            cin >> x;
            switch (x)
            {
            case 1:
                cout << "\nNumber to Enque:  ";
                int y;
                cin >> y;
                enque(y);
                break;
            case 2:
                deque();
                break;

            case 3:
                viewQueue();
                break;
            case 4:
                emptyQueue();
                break;
            case 5:
                break;
            default:
                cout << "\nTry again";
            }
        };
    }

    ~PriorityQueue() {}
};

int main()
{
    PriorityQueue q1;
    q1.menuDriven();
    return 0;
};