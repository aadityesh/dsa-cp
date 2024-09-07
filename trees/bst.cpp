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
void preorderTraversal(TreeNode *root)
{
    // ROOT L R
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(TreeNode *root)
{
    // L R ROOT
    if (root == NULL)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}
// 1 2 4 5 -1 -1 6 -1 -1 -1 3 7 8 -1 -1 -1 9 10 -1 -1 -1
void inorderTraversal(TreeNode *root)
{
    // L ROOT R
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
void levelOrder(TreeNode *root)
{

    vector<vector<int>> res;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++)
        {

            TreeNode *front = q.front();
            q.pop();

            if (front->left)
                q.push(front->left);

            if (front->right)
                q.push(front->right);

            level.push_back(front->data);
        }

        res.push_back(level);
    }

    // Range-based for loops
    for (vector<int> vec : res)
    {
        for (int i : vec)
        {
            cout << i << " ";
        }
        cout << endl;
    }
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

int main()
{

    TreeNode *root = NULL;
    // cout << "Enter data to create BST: " << endl;
    takeInput(root);
    // levelOrder(root);

    // cout << endl;
    preorderTraversal(root);
    // cout << endl;
    // inorderTraversal(root);
    // cout << endl;
    // preorderTraversal(root);

    return 0;
}