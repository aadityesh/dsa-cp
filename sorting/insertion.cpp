#include <bits/stdc++.h>
using namespace std;

void insertion(vector<int> &a)
{

    int n = a.size();
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        j = i;
        while (j != 0 && a[j - 1] > a[j])
        {
            swap(a[j - 1], a[j]);
            j--;
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
    insertion(a);
    for (int i : a)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}