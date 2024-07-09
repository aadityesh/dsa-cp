#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int _data)
    {
        data = _data;
        prev = nullptr;
        next = nullptr;
    }
};

void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(int data, Node *&head)
{
    Node *newNode = new Node(data);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtTail(int data, Node *&head, Node *&tail)
{

    Node *newNode = new Node(data);

    if (head == nullptr)
    {
        tail = newNode;
        head = tail;
        return;
    }

    else
    {
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        tail = temp;
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void insertAtPos(Node *&head, Node *&tail, int data, int pos)
{
    if (pos == 1)
    {
        insertAtHead(data, head);
        return;
    }

    else
    {
        Node *prev = NULL;
        Node *curr = head;

        int times = pos - 1;

        while (times-- && curr->next != nullptr)
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr->next == nullptr)
        {
            insertAtTail(data, head, tail);
            return;
        }

        else
        {
            Node *newNode = new Node(data);
            prev->next = newNode;
            newNode->prev = prev;

            newNode->next = curr;
            curr->prev = newNode;
        }
    }
}

int main()
{
    // Node *head = new Node(4);
    // Node *tail = head;

    Node *head = NULL;
    Node *tail = head;

    insertAtHead(3, head);
    insertAtHead(2, head);
    insertAtHead(1, head);

    printLL(head);

    insertAtTail(5, head, tail);
    insertAtTail(6, head, tail);
    insertAtTail(7, head, tail);
    insertAtTail(8, head, tail);

    printLL(head);

    insertAtPos(head, tail, 3, 3);
    printLL(head);

    insertAtPos(head, tail, 0, 1);
    printLL(head);

    insertAtPos(head, tail, 9, 12);
    printLL(head);

    return 0;
}