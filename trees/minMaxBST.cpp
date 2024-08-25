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

void minimumValueBST(TreeNode *root, int &mini)
{
    if (root == NULL)
        return;

    mini = min(mini, root->data);

    if (root->left)
        minimumValueBST(root->left, mini);

    else
        minimumValueBST(root->right, mini);
}

void maximumValueBST(TreeNode *root, int &maxi)
{
    if (root == NULL)
        return;

    maxi = max(maxi, root->data);

    if (root->right)
        maximumValueBST(root->right, maxi);

    else
        maximumValueBST(root->left, maxi);
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
    takeInput(root);

    int mini = INT_MAX;
    int maxi = INT_MIN;

    minimumValueBST(root, mini);
    maximumValueBST(root, maxi);
    cout << mini << " " << maxi << endl;

    return 0;
}