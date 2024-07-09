#include <bits/stdc++.h>
using namespace std;

double brute(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    int m = b.size();

    int left = 0;
    int right = 0;

    vector<int> arr;

    while (left < n && right < m)
    {
        if (a[left] <= b[right])
            arr.push_back(a[left++]);
        else
            arr.push_back(b[right++]);
    }

    while (left < n)
        arr.push_back(a[left++]);

    while (right < m)
        arr.push_back(b[right++]);

    n = n + m;
    int reqIndex = n / 2;
    if (n % 2 == 0)
    {
        double res = arr[reqIndex - 1] + arr[reqIndex];
        return res / 2.0;
    }

    return double(arr[reqIndex]);
}
double better(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    int m = b.size();

    int left = 0;
    int right = 0;

    int reqIndexOdd = (n + m) / 2;
    int reqIndexEven = ((n + m) / 2) - 1;

    int cnt = 0;
    int ele1 = -1;
    int ele2 = -1;

    vector<int> arr;

    while (left < n && right < m)
    {
        if (a[left] <= b[right])
        {
            if (cnt == reqIndexEven)
                ele1 = a[left];
            if (cnt == reqIndexOdd)
                ele2 = a[left];

            left++;
            cnt++;
        }
        else
        {
            if (cnt == reqIndexEven)
                ele1 = b[right];
            if (cnt == reqIndexOdd)
                ele2 = b[right];

            right++;
            cnt++;
        }
    }

    while (left < n)
    {
        if (cnt == reqIndexEven)
            ele1 = a[left];
        if (cnt == reqIndexOdd)
            ele2 = a[left];

        left++;
        cnt++;
    }

    while (right < m)
    {
        if (cnt == reqIndexEven)
            ele1 = b[right];
        if (cnt == reqIndexOdd)
            ele2 = b[right];

        right++;
        cnt++;
    }

    int totalSize = n + m;
    if (totalSize % 2 == 0)
    {
        double res = (double(ele1) + double(ele2)) / 2.0;
        return res;
    }

    return ele2;
}
double optimal(vector<int> &a, vector<int> &b)
{
    return 1.0;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a;
    vector<int> b;

    for (int i = 0; i < n; i++)
    {
        int elem;
        cin >> elem;
        a.push_back(elem);
    }

    for (int i = 0; i < m; i++)
    {
        int elem;
        cin >> elem;
        b.push_back(elem);
    }

    // cout << brute(a, b) << endl;
    // cout << better(a, b) << endl;
    cout << optimal(a, b) << endl;

    return 0;
}