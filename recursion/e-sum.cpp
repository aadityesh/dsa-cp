#include <bits/stdc++.h>
using namespace std;

void sum(int arr[], int n, int val)
{
    if (n == 0)
    {
        cout << val << endl;
        return;
    }

    val += arr[0];
    sum(arr + 1, n - 1, val);
}

int main()
{
    int arr[5] = {1, 3, 2, 5, 4};
    sum(arr, 5, 0);
    return 0;
}