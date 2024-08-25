#include <bits/stdc++.h>
using namespace std;

void selection(vector<int> &a)
{

    int n = a.size();
    int mini = -1;
    for (int i = 0; i < n; i++)
    {
        mini = i;
        for (int j = i; j < n; j++)
        {
            if (a[mini] > a[j])
            {
                mini = j;
            }
        }
        swap(a[i], a[mini]);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    selection(a);
    for (int i : a)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}