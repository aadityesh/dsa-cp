#include <bits/stdc++.h>
using namespace std;

void bubble(vector<int> &a)
{

    int n = a.size();
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j != 0 && a[j - 1] > a[j])
            {
                swap(a[j - 1], a[j]);
            }
        }
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
    bubble(a);
    for (int i : a)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}