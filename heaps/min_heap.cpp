#include <bits/stdc++.h>

using namespace std;

class MinHeap
{
    int cap;
    int size;
    int *arr;

public:
    MinHeap(int c)
    {
        size = 0;
        cap = c;
        arr = new int[cap];
    }

    int leftIndex(int i)
    {
        return (2 * i + 1);
    }
    int rightIndex(int i)
    {
        return (2 * i + 2);
    }
    int parentIndex(int i)
    {
        return (i - 1) / 2;
    }
    void insert(int data)
    {

        if (size < cap)
        {
            arr[size] = data;
            size++;

            int i = size - 1;
            while (i > 0)
            {
                int parent = parentIndex(i);
                if (arr[parent] > data)
                {
                    swap(arr[i], arr[parent]);
                    i = parent;
                }
                else
                    break;
            }
        }

        else
        {
            cout << "capacity of heap is full" << endl;
            return;
        }
    }

    void heapify(int i)
    {

        int left = leftIndex(i);
        int right = rightIndex(i);
        int mini = i;

        if (left < size && arr[left] < arr[mini])
        {
            mini = left;
        }
        if (right < size && arr[right] < arr[mini])
        {
            mini = right;
        }
        if (mini != i)
        {
            swap(arr[mini], arr[i]);
            heapify(i);
        }
    }

    int getMin()
    {
        return arr[0];
    }

    int extractMin()
    {
        if (size == 0)
        {
            cout << "Heap is empty" << endl;
            return INT_MIN;
        }
        if (size == 1)
        {
            size--;
            return arr[0];
        }
        int ans = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapify(0);
        return ans;
    }

    void decreaseNode(int i, int data)
    {
        arr[i] = data;
        while (i > 0)
        {
            int parent = parentIndex(i);
            if (arr[parent] > data)
            {
                swap(arr[i], arr[parent]);
                i = parent;
            }
            else
                break;
        }
    }

    void deleteNode(int i)
    {
        decreaseNode(i, INT_MIN);
        extractMin();
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void buildHeap()
    {
        int internal = (size - 1 - 1) / 2;
        for (int i = internal; internal >= 0; i--)
            heapify(i);
    }
};

int main()
{

    return 0;
}