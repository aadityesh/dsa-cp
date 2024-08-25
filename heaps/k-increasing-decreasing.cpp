#include <bits/stdc++.h>
using namespace std;

void sortArray(vector<int> &arr, int k)
{
    vector<int> res;
    // Min heap
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < arr.size(); i++)
    {
        if (pq.size() > k + 1)
        {
            int elem = pq.top();
            res.push_back(elem);
            pq.pop();
        }

        pq.push(arr[i]);
    }

    while (!pq.empty())
    {
        int elem = pq.top();
        pq.pop();
        res.push_back(elem);
    }

    for (int i : res)
        cout << i << " ";
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

    sortArray(a, 3);

    return 0;
}