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
        next = nullptr;
    }
};

void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    tail->next = newNode;
    newNode->next = head;
    tail = newNode;
}

void deleteElem(Node *&head, Node *&tail, int data)
{

    Node *curr = head;
    Node *prev = NULL;

    if (curr->data == data)
    {
        head = head->next;
        tail->next = head;
        delete curr;
    }

    else
    {
        while (curr->data != data && curr != tail)
        {
            prev = curr;
            curr = curr->next;
        }

        if (tail->data == data)
        {
            prev->next = head;
            tail = prev;
        }

        else
        {
            prev->next = curr->next;
        }

        delete curr;
    }
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

int main()
{
    Node *head = new Node(1);
    head->next = head;
    Node *tail = head;

    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 5);
    // cout << head->data << " " << tail->next->data << endl;
    printLL(tail);

    // deleteElem(head, tail, 3);
    // printLL(tail);

    // deleteElem(head, tail, 1);
    // printLL(tail);

    deleteElem(head, tail, 5);
    printLL(tail);

    return 0;
}