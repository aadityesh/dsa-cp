#include <bits/stdc++.h>

using namespace std;

class Heap
{

public:
    int size;
    int arr[100];
    Heap()
    {
        size = 0;
    }
    void print()
    {
        cout << "Printing elements:\n";
        cout << size << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void insertion(int elem)
    {

        arr[size] = elem;
        int i = size;
        size++;

        while (i > 0)
        {
            int parent = (i - 1) / 2;
            if (elem > arr[parent])
            {
                swap(arr[parent], arr[i]);
                i = parent;
            }

            else
                return;
        }
    }

    void deletion()
    {
        // last node on top
        arr[0] = arr[size - 1];
        size--;
        int i = 0;

        // place it on the correct position
        while (true)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < size && arr[left] > arr[i])
            {
                swap(arr[i], arr[left]);
                i = left;
            }

            if (right < size && arr[right] > arr[i])
            {
                swap(arr[i], arr[right]);
                i = right;
            }

            else
                return;
        }
    }
};

void heapify(int arr[], int n, int i)
{

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[largest] < arr[left])
        largest = left;

    if (right < n && arr[largest] < arr[right])
        largest = right;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }

    return;
}

void heapSort(int arr[], int n)
{
    int t = n - 1;
    while (t > 0)
    {
        swap(arr[0], arr[t]);
        heapify(arr, t, 0);
        t--;
    }

    cout << "Printing elements:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    Heap obj;
    obj.insertion(88);
    obj.insertion(45);
    obj.insertion(12);
    obj.insertion(36);
    obj.insertion(44);
    obj.insertion(23);
    obj.insertion(8);
    obj.print();
    obj.deletion();
    obj.print();

    int arr[6] = {
        55,
        20,
        45,
        99,
        33,
        75};
    int n = 6;

    for (int i = (n / 2); i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    cout << "Printing elements:\n";
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr, n);

    return 0;
}