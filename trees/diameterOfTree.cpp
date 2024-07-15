#include <bits/stdc++.h>

using namespace std;
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int _data)
    {
        data = _data;
        left = NULL;
        right = NULL;
    }
};

TreeNode *buildTree(TreeNode *root)
{

    int data;
    // cout << "Enter data: ";
    cin >> data;
    root = new TreeNode(data);
    if (data == -1)
    {
        return NULL;
    }
    // cout << "Enter data for left side of " << data << endl;
    root->left = buildTree(root->left);
    // cout << "Enter data for right side of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

int maxHeight(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int lh = maxHeight(root->left);
    int rh = maxHeight(root->right);

    return (1 + max(lh, rh));
}

void Brute(TreeNode *root, int &maxi)
{
    if (root == NULL)
        return;

    // height calculation
    int lh = maxHeight(root->left);
    int rh = maxHeight(root->right);

    maxi = max(maxi, lh + rh);

    // Moving to next nodes
    Brute(root->left, maxi);
    Brute(root->right, maxi);

    // cout << maxi;
}

int Optimal(TreeNode *root, int &maxi)
{
    if (root == NULL)
        return 0;

    int lh = Optimal(root->left, maxi);
    int rh = Optimal(root->right, maxi);
    // cout << lh << rh << endl;
    maxi = max(maxi, lh + rh);

    return 1 + max(lh, rh);

    // cout << maxi;
}

int main()
{
    TreeNode *root = NULL;
    int maxi = 0;
    root = buildTree(root);
    Brute(root, maxi);
    cout << maxi << endl;
    maxi = 0;
    int res = Optimal(root, maxi);
    cout << maxi << endl;
    return 0;
}