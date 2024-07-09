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

Node *BuildTree(Node *root)
{

    int data;
    cout << "Enter data: ";
    cin >> data;
    root = new Node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter data for left side of " << data << endl;
    root->left = BuildTree(root->left);
    cout << "Enter data for right side of " << data << endl;
    root->right = BuildTree(root->right);

    return root;
}

void preorderTraversal(Node *root)
{
    // ROOT L R
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(Node *root)
{
    // L R ROOT
    if (root == NULL)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}
// 1 2 4 5 -1 -1 6 -1 -1 -1 3 7 8 -1 -1 -1 9 10 -1 -1 -1
void inorderTraversal(Node *root)
{
    // L ROOT R
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main()
{
    Node *root = NULL;
    root = BuildTree(root);

    cout << "\n\nPreOrder\n";
    preorderTraversal(root);

    cout << "\nInOrder\n";
    inorderTraversal(root);

    cout << "\nPostOrder\n";
    postorderTraversal(root);
    // levelorderTraversal(root);
    return 0;

    // PreOrder  1 2 4 5 6 3 7 8 9 10
    // InOrder   5 4 6 2 1 8 7 3 10 9
    // PostOrder 5 6 4 2 8 7 10 9 3 1
}