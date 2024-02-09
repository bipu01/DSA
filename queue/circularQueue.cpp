#include <iostream>
using namespace std;
#define MAX 3

class CircularQueue
{
public:
    int data[MAX], front, rear;
    CircularQueue() : front(-1), rear(-1) {}

    void emptyQueue()
    {
        front = -1;
        rear = -1;
    }

    bool isFull()
    {
        return (rear + 1) % MAX == front;
    }

    bool isEmpty()
    {
        return (front == -1 && rear == -1) || (front == rear);
    }

    void enque(int temp)
    {
        if (isFull())
        {
            cout << "The queue is Full\n";
        }
        else if (isEmpty())
        {
            // front++;
            rear = (rear + 1) % MAX;
            data[rear] = temp;
        }
        else if (((rear + 1) % MAX == 0) && front == -1)
        {
            front = 0;
        }
        else
        {
            rear = (rear + 1) % MAX;
            data[rear] = temp;
        }
    }

    void deque()
    {
        if (isEmpty())
        {
            cout << "The Queue is empty";
        }
        else if (front == -1 && rear >= 0)
        {
            front = 0;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }

    void viewQueue()
    {
        if (isEmpty())
        {
            if (rear != -1)
            {
                cout << "[" << data[front % MAX] << "]\n";
                rear = -1;
                front = -1;
            }
        }
        else
        {
            cout << "[ ";
            if (front > rear)
            {
                for (int i = front; i < MAX; i++)
                {
                    cout << " " << data[i];
                }
                for (int i = 0; i <= rear; i++)
                {
                    cout << " " << data[i];
                }
            }
            else if (front <= rear && front == -1)
            {
                for (int i = front + 1; i <= rear; i++)
                {
                    cout << " " << data[i];
                }
            }
            else if (front <= rear)
            {
                for (int i = front; i <= rear; i++)
                {
                    cout << " " << data[i];
                }
            }
            cout << " ]" << endl;
        }
    }

    void menuDriven()
    {

        int x = -1;
        viewQueue();
        while (x != 5)
        {
        here:
            cout << "\nPress: \n";
            cout << "1 to Enque \n";
            cout << "2 to deque \n";
            cout << "3 to view Queue \n";
            cout << "4 to empty the Queue\n";
            cout << "5 to Quit the program \n";
            cout << "\n";
            viewQueue();
            cout << "Inp: ";
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

    ~CircularQueue() {}
};

int main()
{
    CircularQueue c1;
    c1.menuDriven();

    return 0;
};