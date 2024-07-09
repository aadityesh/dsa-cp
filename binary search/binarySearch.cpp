#include <bits/stdc++.h>
using namespace std;

int bs(vector<int> &a, int target)
{

    int low = 0;
    int high = a.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (a[mid] == target)
        {
            return mid;
        }

        else if (target > a[mid])
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int search(vector<int> &a, int target)
{
    // Write your code here.
    int ans = bs(a, target);
    return ans;
}

int main()
{
    vector<int> a = {1, 3, 4, 6, 9, 10};
    int key = 6;

    cout << "key at index: " << search(a, key) << endl;

    return 0;
}