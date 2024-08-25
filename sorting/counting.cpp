#include <bits/stdc++.h>
using namespace std;

void counting(vector<int> &arr)
{
    int n = arr.size();
    vector<int> o(n);

    // 1. Find Max
    int maxi = *max_element(arr.begin(), arr.end());
    int hash[maxi + 1] = {0};

    // 2. Hashing/Frequency Count
    for (int i = 0; i < n; i++)
        hash[arr[i]]++;

    // 3. Cumulative Sum
    for (int i = 1; i <= maxi; i++)
        hash[i] = hash[i] + hash[i - 1];

    // 4. Output Array
    for (int i = n - 1; i >= 0; i--)
    {
        o[hash[arr[i]] - 1] = arr[i];
        hash[arr[i]]--;
    }

    for (int i : o)
    {
        cout << i << " ";
    }
    cout << endl;
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
    counting(a);
    return 0;
}