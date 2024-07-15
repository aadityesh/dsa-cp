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

int maximumSumPath(TreeNode *root, int &res)
{
    if (!root)
        return 0;

    int lh = maximumSumPath(root->left, res);
    int rh = maximumSumPath(root->right, res);

    // Ignoring -ve values
    // inorder to maximize the sum

    lh = (lh >= 0) ? lh : 0;
    rh = (rh >= 0) ? rh : 0;

    // This statement helps us to calculate sum
    // for the current tree
    res = max(res, lh + rh + root->data);

    // This statement ensures we choose the
    // the maximum path for the next iteration
    return max(lh, rh) + root->data;
}

int maxPathSum(TreeNode *root)
{
    if (!root)
        return 0;

    int res = INT_MIN;
    int p = maximumSumPath(root, res);

    return res;
}

int main()
{
    TreeNode *root = NULL;
    root = buildTree(root);

    cout << maxPathSum(root) << endl;

    return 0;
}