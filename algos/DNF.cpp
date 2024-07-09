#include <bits/stdc++.h>
using namespace std;

void DNF(int *a, int n)
{

    int low = 0;      // ending of Zero Box
    int mid = 0;      // traverse the unsorted part
    int high = n - 1; // starting of "2" Box

    while (mid <= high)
    {
        // mid = 0, 1, 2
        if (a[mid] == 0)
            swap(a[low++], a[mid++]);
        if (a[mid] == 2)
            swap(a[high--], a[mid]); // 0, 1
        if (a[mid] == 1)
            mid++;
    }

    cout << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    // cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    DNF(a, n);

    return 0;
}