#include <bits/stdc++.h>

using namespace std;

int main()
{
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;

    maxheap.push(565);
    maxheap.push(56);
    maxheap.push(500);
    maxheap.push(15);

    maxheap.pop();

    maxheap.top();

    maxheap.size();

    maxheap.empty();

    // int size = maxheap.size();
    while (!maxheap.empty())
    {
        cout << maxheap.top() << " ";
        maxheap.pop();
    }
    cout << endl;

    return 0;
}