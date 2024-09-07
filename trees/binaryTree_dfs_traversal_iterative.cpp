#include <bits/stdc++.h>
using namespace std;

struct Node
{
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

Node *BuildTree(Node *root)
{

    int data;
    // cout << "Enter data: ";
    cin >> data;
    root = new Node(data);
    if (data == -1)
    {
        return NULL;
    }
    // cout << "Enter data for left side of " << data << endl;
    root->left = BuildTree(root->left);
    // cout << "Enter data for right side of " << data << endl;
    root->right = BuildTree(root->right);

    return root;
}

void preorder(Node *node)
{
    // ROOT L R
    if (node == NULL)
        return;

    stack<Node *> st;
    st.push(node);

    while (!st.empty())
    {
        Node *current = st.top();
        st.pop();

        cout << current->data << " ";
        if (current->right)
            st.push(current->right);
        if (current->left)
            st.push(current->left);
    }
}
void inorder(Node *root)
{
    vector<int> res;
    stack<Node *> st;
    Node *node = root;
    while (true)
    {
        if (node != NULL)
        {
            st.push(node);
            node = node->left;
        }

        else
        {
            if (st.empty())
                break;
            node = st.top();
            st.pop();
            res.push_back(node->data);
            node = node->right;
        }
    }

    cout << endl;
    for (auto i : res)
        cout << i << " ";
}
void postorderTwoStacks(Node *node)
{
    stack<Node *> st1;
    stack<int> st2;
    st1.push(node);

    while (!st1.empty())
    {
        Node *current = st1.top();
        st1.pop();
        // PreOrder : r L R
        // PostOrder : L R r
        // stack is LIFO
        st2.push(current->data);
        if (current->left)
            st1.push(current->left);
        if (current->right)
            st1.push(current->right);

        // left right root
    }

    while (!st2.empty())
    {
        cout << st2.top() << " ";
        st2.pop();
    }
}
void postorderOneStack(Node *node)
{
    stack<Node *> st;
    vector<int> res;
    Node *curr = node;

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

            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                res.push_back(temp->data); // reached leaf node

                // going back to the root
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    res.push_back(temp->data);
                }
            }

            else
            {
                curr = temp;
            }
        }
    }

    for (auto i : res)
        cout << i << " ";
    cout << endl;
}
void preorderTraversalRec(Node *root)
{
    // ROOT L R
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorderTraversalRec(root->left);
    preorderTraversalRec(root->right);
}
void postorderRec(Node *root)
{
    // L R ROOT
    if (root == NULL)
        return;

    postorderRec(root->left);
    postorderRec(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *root = NULL;
    root = BuildTree(root);

    cout << endl;
    // cout << endl;

    // cout << endl;
    // preorder(root);
    // cout << endl;
    // cout << endl;
    // cout << endl;
    // preorderTraversalRec(root);
    cout << endl;
    // cout << endl;
    cout << endl;
    inorder(root);
    // postorderTwoStacks(root);
    cout << endl;
    // postorderRec(root);

    return 0;
}