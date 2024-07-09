#include <bits/stdc++.h>
using namespace std;

int bs(vector<int> &a, int target, int low, int high)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (a[mid] == target)
    {
        return mid;
    }

    else if (target > a[mid])
    {
        return bs(a, target, mid + 1, high);
    }

    else
    {
        return bs(a, target, low, mid - 1);
    }
}

int search(vector<int> &a, int target)
{
    // Write your code here.
    int ans = bs(a, target, 0, a.size() - 1);
    return ans;
}

int main()
{
    vector<int> a = {1, 3, 4, 6, 9, 10};
    int key = 6;

    cout << "key at index: " << search(a, key) << endl;

    return 0;
}