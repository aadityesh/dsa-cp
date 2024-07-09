#include <bits/stdc++.h>
using namespace std;

class Queue
{

    int *arr;
    int front;
    int rear;
    int size;

public:
    Queue(int _size)
    {
        front = rear = -1;
        size = _size;
        arr = new int[size];
    }

    /*
     * push
     * pop
     * empty
     * Display
     */

    void push(int x)
    {
        // empty
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
            arr[rear] = x;
        }
        // full
        else if ((rear + 1) % size == front)
        {
            cout << "Overflow" << endl;
        }

        else
        {
            rear = (rear + 1) % size;
            arr[rear] = x;
        }
    }

    int pop()
    {
        // empty
        if (front == -1 && rear == -1)
        {
            cout << "Underflow" << endl;
        }
        // one element
        else if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
    }
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            cout << "True" << endl;
        }
        else
        {
            cout << "False" << endl;
        }
    }

    void displayQueue()
    {
        if (front == -1 && rear == -1)
            cout << "Queue is empty" << endl;
        else
        {
            int i = front;
            while (i != rear)
            {
                cout << arr[i] << " ";
                i = (i + 1) % size;
            }
            cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main()
{
    Queue q(5);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    q.displayQueue();
    q.pop();
    q.displayQueue();

    return 0;
}