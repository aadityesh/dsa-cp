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

class Stack
{
    Node *top; // head of the Linked List

public:
    Stack()
    {
        top = NULL;
    }

    void push(int _data)
    {
        Node *newNode = new Node(_data);
        newNode->next = top;
        top = newNode;
    }

    int topElement()
    {
        return top->data;
    }

    int pop()
    {
        if (top == NULL)
        {
            return -1;
        }

        Node *toDelete = top;
        top = top->next;
        cout << "node with data -> " << toDelete->data << " is deleted." << endl;
        delete (toDelete);
    }

    bool empty()
    {
        return top == NULL;
    }

    void Display()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            Node *temp = top;
            while (temp)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
        cout << endl;
    }
};

int main()
{
    Stack st;
    st.push(11);
    st.push(12);
    st.push(13);
    st.push(14);
    st.Display();
    st.pop();
    st.Display();
    cout << st.empty() << endl;

    return 0;
}