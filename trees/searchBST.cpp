#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

TreeNode *buildBST(TreeNode *root, int data)
{
    if (root == NULL)
    {
        TreeNode *node = new TreeNode(data);
        return node;
    }

    if (data > root->data)
    {
        root->right = buildBST(root->right, data);
    }

    else
    {
        root->left = buildBST(root->left, data);
    }

    return root;
}

bool searchBST(TreeNode *root, int target)
{

    if (root == NULL)
        return false;

    if (root->data == target)
        return true;

    if (root->data > target)
        return searchBST(root->left, target);

    return searchBST(root->right, target);
}

void takeInput(TreeNode *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = buildBST(root, data);
        cin >> data;
    }
}

void preorderTraversal(TreeNode *root)
{
    // ROOT L R
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main()
{

    TreeNode *root = NULL;
    // cout << "Enter data to create BST: " << endl;
    takeInput(root);

    int target = 7;
    cout << "target " << target << " present(0/1): " << searchBST(root, target) << endl;

    return 0;
}