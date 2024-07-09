#include <bits/stdc++.h>
using namespace std;

void displayQueue(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;
}

int main()
{
    /*
     * push
     * pop
     * empty
     * size
     */
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);

    displayQueue(q);
    cout << "Size: " << q.size() << endl;
    cout << "isEmpty: " << q.empty() << endl;

    cout << "Front: " << q.front() << endl;
    cout << "Pop method" << endl;
    q.pop();
    cout << "Front: " << q.front() << endl;

    return 0;
}

/*#include <bits/stdc++.h>

class Node {
public:
  int data;
  Node *next;
  Node(int _data) {
    data = _data;
    next = NULL;
  }
};

class Queue {

  Node *head;
  Node *tail;

public:
  Queue() : head(nullptr), tail(nullptr) {}

  bool isEmpty() { return head == nullptr; }

  void enqueue(int data) {
    Node *curr = new Node(data);
    if (head == nullptr) {
      tail = curr;
      head = tail;
    } else {
      tail->next = curr;
      tail = tail->next;
    }
  }

  int dequeue() {

    if (head == NULL)
      return -1;

    int res = head->data;
    Node *temp = head;

    head = head->next;

    delete (temp);
    return res;
  }

  int front() {
    if (head == NULL)
      return -1;

    return head->data;
  }
};*/

/*
 class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};


// Function to push an element x in a queue.
void MyQueue ::push(int x)
{
    arr[rear++] = x;
}

// Function to pop an element from queue and return that element.
int MyQueue ::pop()
{
    if (rear == 0 || front == rear)
        return -1;

    int res = arr[front++];
    return res;
}
*/