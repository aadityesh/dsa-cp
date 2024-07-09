#include <bits/stdc++.h>
using namespace std;

void putInCorrectPosition(int elem, stack<int> &st)
{
    if (st.empty())
    {
        st.push(elem);
        return;
    }

    int top = st.top();
    st.pop();

    putInCorrectPosition(elem, st);
    st.push(top);
}

void reverse(stack<int> &st)
{

    if (st.empty())
        return;

    int top = st.top();
    st.pop();

    reverse(st);
    putInCorrectPosition(top, st);
}

void print(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main()
{
    int n, elem;
    cin >> n;
    stack<int> st;

    while (n--)
    {
        cin >> elem;
        st.push(elem);
    }

    print(st);
    reverse(st);
    print(st);

    return 0;
}