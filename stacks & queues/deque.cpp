#include <bits/stdc++.h>
using namespace std;

class Deque
{
    int front;
    int rear;
    int *arr;
    int n;

public:
    Deque(int _n)
    {
        n = _n;
        front = rear = -1;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return ((front == 0 && rear == n - 1) || (front == rear + 1));
    }

    void pushFront(int x)
    {
        // full
        if (isFull())
        {
            cout << "Overflow" << endl;
            return;
        }

        // empty
        else if (isEmpty())
        {
            front = rear = 0;
        }

        else if (front == 0)
        {
            front = n - 1;
        }

        else
        {
            front = front - 1;
        }

        arr[front] = x;
    }
    void pushRear(int x)
    {
        if (isEmpty())
        {
            front = rear = 0;
        }
        // full
        else if (isFull())
        {
            cout << "Overflow" << endl;
        }
        else if (rear == n - 1)
        {
            rear = 0;
        }
        else
        {
            rear = (rear + 1);
        }
        arr[rear] = x;
    }

    int popFront()
    {
        if (isEmpty())
        {
            cout << "Underflow" << endl;
            return -1;
        }

        else
        {
            int res = arr[front];
            if (front == rear)
            {
                front = rear = -1;
            }

            else if (front == n - 1)
            {
                front = 0;
            }

            else
            {
                front++;
            }

            return res;
        }
    }
    int popRear()
    {

        if (isEmpty())
        {
            cout << "Underflow" << endl;
            return -1;
        }
        else
        {

            int res = arr[rear];

            if (front == rear)
            {
                front = rear = -1;
            }
            else if (rear == 0)
            {
                rear = n - 1;
            }
            else
            {
                rear--;
            }

            return res;
        }
    }

    void Display()
    {
        if (isEmpty())
        {
            cout << "Empty" << endl;
            return;
        }

        int i = front;
        while (i != rear)
        {
            cout << arr[i] << " ";
            i = (i + 1) % n;
        }
        cout << arr[i] << endl;
    }
};

int main()
{

    Deque q(5);
    q.pushFront(1);
    q.pushRear(2);
    q.pushFront(3);
    q.pushRear(4);
    q.pushFront(5);

    q.Display();

    q.popFront();
    q.popRear();

    q.Display();

    return 0;
}