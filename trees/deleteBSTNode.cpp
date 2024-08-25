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

TreeNode *deleteNode(TreeNode *root, int target)
{

    if (root == NULL)
        return nullptr;

    if (root->data == target)
    {

        // #1 : 0 Children
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }
        // #2 : 1 Children
        else if (root->left || root->right)
        {
            TreeNode *child = (root->left == nullptr) ? root->right : root->left;
            delete root;
            return child;
        }
        // #3 : 2 Children
        else
        {
            int maxi = INT_MIN;
            maximumValueBST(root->left, maxi);
            root->data = maxi;
            root->left = deleteNode(root->left, maxi);

            return root;
        }
    }

    if (root->data > target)
    {
        root->left = deleteNode(root->left, target);
        return root;
    }

    else
    {
        root->right = deleteNode(root->right, target);
        return root;
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

void inorderTraversal(TreeNode *root)
{
    // ROOT L R
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main()
{

    TreeNode *root = NULL;
    // cout << "Enter data to create BST: " << endl;
    takeInput(root);

    // int target = 7;
    // cout << "target " << target << " present(0/1): " << searchBST(root, target) << endl;
    inorderTraversal(root);
    deleteNode(root, 10);
    cout << "\n\n";
    inorderTraversal(root);

    return 0;
}