#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(int data, Node *&head)
{
    Node *a = new Node(data);
    a->next = head;
    head = a;
}

void insertAtTail(int data, Node *&tail)
{
    Node *a = new Node(data);
    tail->next = a;
    tail = a;
}

void insertAtPos(int data, Node *&head, Node *&tail, int pos)
{

    Node *curr = head;
    Node *prev = head;

    int cnt = 0;

    if (pos == 1)
    {
        insertAtHead(data, head);
        return;
    }

    while (cnt < pos - 1)
    {
        prev = curr;
        curr = curr->next;
        cnt++;
    }

    if (curr == NULL)
    {
        Node *a = new Node(data);
        prev->next = a;
        tail = a;
        return;
    }

    Node *a = new Node(data);
    prev->next = a;
    a->next = curr;
}

void printLL(Node *head)
{
    Node *curr = head;
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    // cout << curr->data << " ";
    cout << endl;
}

int main()
{
    Node *head = new Node(1);
    Node *tail = head;
    // insertAtHead(5, head);
    insertAtTail(3, tail);
    insertAtTail(4, tail);
    insertAtTail(5, tail);
    insertAtTail(6, tail);
    insertAtTail(7, tail);
    insertAtTail(8, tail);

    printLL(head);
    insertAtPos(2, head, tail, 2);
    printLL(head);

    // cout << head->data << endl;
    // cout << tail->data << endl;

    return 0;
}