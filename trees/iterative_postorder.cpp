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
    // cout << "Enter data: ";
    cin >> data;
    node = new Node(data);

    if (data == -1)
        return NULL;

    // cout << "Enter data for left side of " << data << endl;
    node->left = BuildTree(node->left);
    // cout << "Enter data for right side of " << data << endl;
    node->right = BuildTree(node->right);

    return node;
}

vector<int> postorderTraversal1(Node *root)
{
    if (root == NULL)
        return {};

    vector<int> postorder;
    stack<Node *> st1;
    stack<Node *> st2;

    st1.push(root);

    while (!st1.empty())
    {

        Node *curr = st1.top();
        st1.pop();

        if (curr->left)
            st1.push(curr->left);
        if (curr->right)
            st1.push(curr->right);

        st2.push(curr);
    }

    while (!st2.empty())
    {
        postorder.push_back(st2.top()->data);
        st2.pop();
    }

    return postorder;
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
}
vector<int> postorderTraversal2(Node *root)
{
    if (root == NULL)
        return {};

    vector<int> postorder;
    stack<Node *> st1;
    stack<Node *> st2;

    st1.push(root);

    while (!st1.empty())
    {

        Node *curr = st1.top();
        st1.pop();

        if (curr->left)
            st1.push(curr->left);
        if (curr->right)
            st1.push(curr->right);

        st2.push(curr);
    }

    while (!st2.empty())
    {
        postorder.push_back(st2.top()->data);
        st2.pop();
    }

    return postorder;
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
}
void postorderOneStack(Node *root)
{
    // L R N

    stack<Node *> st;
    Node *curr = root;

    while (curr || !st.empty())
    {
        if (curr)
        {
            st.push(curr);
            curr = curr->left;
        }

        else
        {
            Node *temp = st.top()->right;
            if (temp) // marks the start of a new sub-tree.
            {
                curr = temp;
            }

            else
            {
                // backtracking
                temp = st.top();
                cout << temp->data << " ";
                st.pop();

                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    cout << temp->data << " ";
                    st.pop();
                }
            }
        }
    }
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

    vector<int> res = postorderTraversal1(root);

    for (int &i : res)
        cout << i << " ";

    return 0;
}