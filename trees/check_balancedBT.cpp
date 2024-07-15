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
int maxHeight(Node *root)
{

    if (root == NULL)
        return 0;

    int left = maxHeight(root->left);
    int right = maxHeight(root->right);

    return (1 + max(left, right));
}
bool checkBalanced(Node *root)
{

    // base case
    if (root == NULL)
        return true;

    int lh = maxHeight(root->left);
    int rh = maxHeight(root->right);

    if (abs(lh - rh) > 1)
        return false;
}

int main()
{
    Node *root = NULL;
    root = BuildTree(root);

    cout << "\n\n\n";
    checkBalanced(root);

    return 0;
}
