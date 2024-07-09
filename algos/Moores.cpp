#include <bits/stdc++.h>
using namespace std;

int MVA(int *arr, int n)
{
    int elem = arr[0]; // candidate
    int cnt = 1;

    // Two Phases
    // 1. Finding the Majority Element
    // 2. Verfication (cnt > n/2)
    for (int i = 1; i < n; i++)
    {

        if (elem == arr[i])
            cnt++;
        else if (cnt == 0)
        {
            elem = arr[i];
            cnt = 1;
        }
        else
            cnt--;
    }
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (elem == arr[i])
            cnt++;
    }

    if (cnt > (n / 2))
    {
        return elem;
    }

    return -1;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Majority Element: " << MVA(a, n) << endl;
    return 0;
}