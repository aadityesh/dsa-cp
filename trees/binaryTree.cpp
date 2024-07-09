#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int _data)
    {
        data = _data;
        left = NULL;
        right = NULL;
    }
};

Node *BuildTree(Node *node)
{

    int data;
    cout << "Enter data: ";
    cin >> data;
    node = new Node(data);

    if (data == -1)
        return NULL;

    cout << "Enter data for left side of " << data << endl;
    node->left = BuildTree(node->left);
    cout << "Enter data for right side of " << data << endl;
    node->right = BuildTree(node->right);

    return node;
}

void preorderTraversal(Node *node)
{
    // Root L R
    // L Root R
    // L R Root
    if (node == NULL)
        return;
    cout << node->data << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
}

int main()
{
    /*
       1 2 -1 -1 3 -1 -1
            1
           / \
          2  3
    */
    Node *root = NULL;
    root = BuildTree(root);
    cout << endl;
    cout << endl;
    cout << endl;
    preorderTraversal(root);

    return 0;
}