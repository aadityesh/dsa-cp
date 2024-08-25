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
bool isLeaf(TreeNode *root)
{
    if (root->left == NULL && root->right == NULL)
        return true;

    return false;
}
void addLeftBoundary(TreeNode *root, vector<int> &res)
{
    TreeNode *curr = root->left;
    while (curr)
    {
        if (!isLeaf(curr))
            res.push_back(curr->data);
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
};

void addLeafNodes(TreeNode *root, vector<int> &res)
{

    if (root == NULL)
        return;
    if (isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }

    addLeafNodes(root->left, res);
    addLeafNodes(root->right, res);
};

void addRightBoundaryReverse(TreeNode *root, vector<int> &res)
{
    TreeNode *curr = root->right;
    vector<int> temp;

    while (curr)
    {
        if (!isLeaf(curr))
            temp.push_back(curr->data);
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }

    int n = temp.size();
    for (int i = n - 1; i >= 0; i--)
    {
        res.push_back(temp[i]);
    }
};

int main()
{

    /*
     * Steps -
     * 1. Add LEFT Nodes excluding leaf Nodes
     * 2. Add Leaf Nodes
     * 3. Add RIGHT Nodes excluding leaf Nodes
     */

    TreeNode *root = NULL;
    root = buildTree(root);

    vector<int> res;
    if (!root)
        return 0;

    if (!isLeaf(root))
        res.push_back(root->data);

    addLeftBoundary(root, res);
    addLeafNodes(root, res);
    addRightBoundaryReverse(root, res);

    for (int elem : res)
        cout << elem << " ";

    return 0;
}