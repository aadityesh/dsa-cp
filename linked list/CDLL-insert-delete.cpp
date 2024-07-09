#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node *prev;

    Node(int _data)
    {
        data = _data;
        next = nullptr;
        prev = nullptr;
    }
};

void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    newNode->prev = tail;
    newNode->next = head;

    tail->next = newNode;
    tail = newNode;
}

void printLL(Node *tail)
{
    Node *temp = tail->next;
    while (temp != tail)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << " ";
    cout << endl;
}

void deleteElem(Node *&head, Node *&tail, int data)
{

    if (head->data == data)
    {
        Node *curr = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        delete curr;
    }

    else
    {
        Node *prev = NULL;
        Node *curr = head;

        while (curr->data != data && curr != tail)
        {
            prev = curr;
            curr = curr->next;
        }

        if (tail->data == data)
        {
            prev->next = head;
            head->prev = prev;
            tail = prev;
        }
        else
        {
            prev->next = curr->next;
            curr->next->prev = prev;
        }

        delete curr;
    }
}

int main()
{
    Node *head = new Node(1);
    head->prev = head->next = head;
    Node *tail = head;

    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 5);

    printLL(tail);

    deleteElem(head, tail, 3);
    printLL(tail);

    deleteElem(head, tail, 1);
    printLL(tail);

    deleteElem(head, tail, 5);
    printLL(tail);
    return 0;
}