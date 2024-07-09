#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int _data)
    {
        data = _data;
        next = nullptr; // NULL
    }
};

void insertAtTail(int data, Node *&tail)
{
    Node *a = new Node(data);
    tail->next = a;
    tail = a;
}

void printLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteNodeAtPos(Node *&head, Node *&tail, int pos)
{
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *curr = head;
    Node *prev = NULL;
    int times = pos - 1;
    while (times-- && curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr->next == NULL)
    {
        prev->next = nullptr;
        tail = prev;
    }
    else
    {
        prev->next = curr->next;
    }
    delete curr;
}

int main()
{
    Node *head = new Node(1);
    Node *tail = head;

    insertAtTail(2, tail);
    insertAtTail(3, tail);
    insertAtTail(4, tail);
    insertAtTail(5, tail);
    insertAtTail(6, tail);

    printLL(head);

    deleteNodeAtPos(head, tail, 1);
    printLL(head);

    // deleteNodeAtPos(head, tail, 3);
    // printLL(head);

    // deleteNodeAtPos(head, tail, 5);
    // printLL(head);

    return 0;
}