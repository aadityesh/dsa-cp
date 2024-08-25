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

void helper(TreeNode *root, vector<vector<int>> &res)
{

    queue<TreeNode *> q;
    q.push(root);
    int index = 1;

    while (!q.empty())
    {

        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++)
        {

            TreeNode *curr = q.front();
            q.pop();

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);

            level.push_back(curr->val);
        }

        if (index % 2 == 0)
            reverse(level.begin(), level.end());

        res.push_back(level);
        index++;
    }
}

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{

    if (root == NULL)
        return {};

    vector<vector<int>> res;
    helper(root, res);

    return res;
}

int main()
{
    TreeNode *root = NULL;
    root = buildTree(root);

    vector<vector<int>> res =
        zigzagLevelOrder(root);

    for (vector<int> vec : res)
    {
        for (int elem : vec)
        {
            cout << elem << " ";
        }
        cout << "\n";
    }

    return 0;
}