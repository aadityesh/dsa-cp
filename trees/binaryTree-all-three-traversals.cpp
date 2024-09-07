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

Node *buildTree(Node *root)
{
    // cout << "Enter data: ";
    int data;
    cin >> data;
    if (data == -1)
        return NULL;

    root = new Node(data);

    // cout << "Enter data for left side of " << data << ": " << endl;
    root->left = buildTree(root->left);

    // cout << "Enter data for right side of " << data << ": " << endl;
    root->right = buildTree(root->right);

    return root;
}

void allTraversals(Node *root)

{
    stack<pair<Node *, int>> st;
    vector<int> pre, in, post;
    st.push({root, 1});

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->left)
                st.push({it.first->left, 1});
        }
        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->right)
                st.push({it.first->right, 1});
        }
        else
        {
            post.push_back(it.first->data);
        }
    }

    cout << "\n\nPreOrder\n";
    for (auto elem : pre)
        cout << elem << " ";

    cout << "\nInOrder\n";
    for (auto elem : in)
        cout << elem << " ";

    cout << "\nPostOrder\n";
    for (auto elem : post)
        cout << elem << " ";
}

int main()
{
    Node *root = nullptr;
    root = buildTree(root);
    allTraversals(root);

    return 0;
}