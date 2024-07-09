#include <bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int i, int n, int key)
{
    if (n == 0)
        return -1;

    if (arr[0] == key)
        return i;

    else
        linearSearch(arr + 1, i + 1, n - 1, key);
}

int main()
{
    int n = 6;
    int arr[n] = {2, 6, 1, 0, 5, 8};
    int key = 5;

    cout << linearSearch(arr, 0, n, key) << endl;

    return 0;
}