#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int _data)
    {
        data = _data;
        left = NULL;
        right = NULL;
    }
};

Node *BuildTree(Node *node)
{

    int data;
    cout << "Enter data: ";
    cin >> data;
    node = new Node(data);

    if (data == -1)
        return NULL;

    cout << "Enter data for left side of " << data << endl;
    node->left = BuildTree(node->left);
    cout << "Enter data for right side of " << data << endl;
    node->right = BuildTree(node->right);

    return node;
}

vector<int> inorderTraversal(Node *root)
{
    if (root == NULL)
        return {};

    vector<int> inorder;
    stack<Node *> st;

    Node *curr = root;

    while (true)
    {
        if (curr)
        {
            st.push(curr);
            curr = curr->left;
        }

        else
        {
            if (st.empty())
                break;

            curr = st.top();
            st.pop();

            inorder.push_back(curr->data);
            curr = curr->right;
        }
    }

    return inorder;
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
}

int main()
{
    /*
       1 2 -1 -1 3 -1 -1
            1
           / \
          2  3
    */
    Node *root = NULL;
    root = BuildTree(root);
    cout << endl;

    vector<int> res = inorderTraversal(root);

    for (int &i : res)
        cout << i << " ";

    return 0;
}