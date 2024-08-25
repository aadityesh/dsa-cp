#include <bits/stdc++.h>
using namespace std;

void findRank(vector<int> &arr)
{

    vector<int> sorted = arr;
    unordered_map<int, int> umap;
    sort(sorted.begin(), sorted.end());

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < sorted.size(); j++)
        {
            if (arr[i] == sorted[j])
            {
                arr[i] = j + 1;
                break;
            }
        }
    }

    /*
    int curr = -1;
    int r = 0;

    for (int i = 0; i < sorted.size(); i++)
    {
        if (curr != sorted[i])
        {
            r++;
            curr = sorted[i];
            umap[curr] = r;
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = umap[arr[i]];
    }
*/
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
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
    findRank(a);

    return 0;
}