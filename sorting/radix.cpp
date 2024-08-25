#include <bits/stdc++.h>
using namespace std;

void counting(int *arr, int n, int p)
{
    int o[n];

    // 1. Find Max
    int hash[10] = {0};
    int N = int(pow(10, p));

    /*

    -  Expression
       (arr[i] / N) % 10 => helps extract digit from R to L

    */

    // 2. Hashing/Frequency Count
    for (int i = 0; i < n; i++)
        hash[(arr[i] / N) % 10]++;

    // 3. Cumulative Sum
    for (int i = 1; i < 10; i++)
        hash[i] = hash[i] + hash[i - 1];

    // 4. Output Array
    for (int i = n - 1; i >= 0; i--)
    {
        int ind = (arr[i] / N) % 10;
        o[hash[ind] - 1] = arr[i];
        hash[ind]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = o[i];
}

void radixSort(int arr[], int n)
{
    int maxi = -1;
    for (int i = 0; i < n; i++)
        maxi = max(maxi, arr[i]);

    int maxLen = floor(log10(maxi)) + 1;
    int i = 0;

    while (maxLen--)
    {
        counting(arr, n, i);
        i++;
    }
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        radixSort(arr, n);

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
    return 0;
}
// } Driver Code Ends