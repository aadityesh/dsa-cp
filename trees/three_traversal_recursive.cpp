#include <bits/stdc++.h>
using namespace std;

struct Node
{
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

Node *BuildTree(Node *root)
{

    int data;
    // cout << "Enter data: ";
    cin >> data;
    root = new Node(data);
    if (data == -1)
    {
        return NULL;
    }
    // cout << "Enter data for left side of " << data << endl;
    root->left = BuildTree(root->left);
    // cout << "Enter data for right side of " << data << endl;
    root->right = BuildTree(root->right);

    return root;
}

void inorder(Node *root)
{
    if (!root)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(Node *root)
{
    if (!root)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root)
{
    if (!root)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *root = NULL;
    root = BuildTree(root);
    d

            cout
        << "Preorder: " << endl;
    preorder(root);
    cout << endl;

    cout << "inorder: " << endl;
    inorder(root);
    cout << endl;

    cout << "Postorder: " << endl;
    postorder(root);
    cout << endl;

    return 0;
}