#include <bits/stdc++.h>
using namespace std;

vector<int> increasing(vector<int> &a, stack<int> &st)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() < a[i])
        {
            st.pop();
        }

        st.push(a[i]);
    }

    vector<int> res(st.size(), 0);

    int i = st.size() - 1;
    while (!st.empty())
    {
        res[i--] = st.top();
        st.pop();
    }

    return res;
}

int main()
{
    int n, elem;
    cin >> n;

    vector<int> a;
    stack<int> st;

    while (n--)
    {
        cin >> elem;
        a.push_back(elem);
    }

    a = increasing(a, st);
    for (int i : a)
    {
        cout << i << " ";
    }

    return 0;
}