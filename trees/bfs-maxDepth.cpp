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

int maxDepth(TreeNode *root)
{

    if (root == NULL)
        return 0;

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    return (1 + max(left, right));
}

int maxDepthLevelOrder(TreeNode *root)
{
    queue<TreeNode *> q;
    vector<vector<int>> res;
    q.push(root);

    while (!q.empty())
    {

        vector<int> level;
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            TreeNode *curr = q.front();
            q.pop();

            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);

            level.push_back(curr->data);
        }

        res.push_back(level);
    }

    return res.size();
}

int main()
{
    TreeNode *root;
    root = buildTree(root);

    cout << "\n\nMax Depth (Recursion): " << maxDepth(root) << endl;
    cout << "\nMax Depth (Level Order): " << maxDepthLevelOrder(root) << endl;

    return 0;
}