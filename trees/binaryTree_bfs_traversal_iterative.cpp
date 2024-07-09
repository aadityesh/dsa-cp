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
void levelOrder(Node *node)
{
    if (node == NULL)
        return;

    vector<vector<int>> ans;
    queue<Node *> q;
    q.push(node);

    while (!q.empty())
    {

        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++)
        {
            Node *current = q.front();
            q.pop();

            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);

            level.push_back(current->data);
        }

        ans.push_back(level);
    }

    cout << "\nlevel Order:-\n";
    for (auto vec : ans)
    {
        for (auto i : vec)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main()
{
    Node *root = NULL;
    root = BuildTree(root);

    cout << "\n\n\n";
    levelOrder(root);

    return 0;
}
