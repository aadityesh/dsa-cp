#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
    // int cap; /* ignoring capacity */
    vector<int> vec;

public:
    MaxHeap(vector<int> _vec)
    {
        vec = _vec;
        buildHeap(vec);
    }

    void heapify(vector<int> &arr, int i, int e)
    {
        int largest = i;
        int size = e;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left <= size && arr[left] > arr[largest])
            largest = left;

        if (right <= size && arr[right] > arr[largest])
            largest = right;

        if (largest != i)
        {
            swap(arr[largest], arr[i]);
            heapify(arr, largest, size);
        }
    }

    void buildHeap(vector<int> &vec)
    {
        int lastIndex = vec.size() - 1;
        int internalNodes = (lastIndex - 1) / 2;

        for (int i = internalNodes; i >= 0; i--)
        {
            heapify(vec, i, lastIndex);
        }
    }

    void heapSortUtility(vector<int> &arr, int endIndex)
    {
        if (endIndex <= 0)
            return;
        swap(arr[0], arr[endIndex]);
        heapify(arr, 0, endIndex - 1);
        heapSortUtility(arr, endIndex - 1);
    }

    void heapSort()
    {
        vector<int> arr = vec;
        int e = arr.size() - 1;
        heapSortUtility(arr, e);

        cout << "HeapSort: " << endl;
        for (int i : arr)
            cout << i << " ";
        cout << endl;
    }

    void print()
    {
        cout << "Heap: " << endl;
        for (int i : vec)
            cout << i << " ";
        cout << endl;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    MaxHeap obj(a);
    obj.print();
    obj.heapSort();
    return 0;
}