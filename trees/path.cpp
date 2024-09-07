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

bool generatePath(TreeNode *root, vector<int> &path, int key)
{
    if (root == NULL)
        return false;

    path.push_back(root->val);

    if (root->val == key)
        return true;

    if (generatePath(root->left, path, key) || generatePath(root->right, path, key))
        return true;

    path.pop_back();
    return false;
}

int main()
{
    TreeNode *root = nullptr;
    root = buildTree(root);

    vector<int> path;
    int key = 7;
    generatePath(root, path, key);

    return 0;
}