//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
private:
    void merge(int arr[], int l, int m, int r)
    {
        int L = l;
        int R = m + 1;

        vector<int> temp;

        while (L <= m && R <= r)
        {
            if (arr[L] <= arr[R])
                temp.push_back(arr[L++]);
            else
                temp.push_back(arr[R++]);
        }

        while (L <= m)
        {
            temp.push_back(arr[L++]);
        }

        while (R <= r)
        {
            temp.push_back(arr[R++]);
        }

        for (int i = l; i <= r; i++)
        {
            arr[i] = temp[i - l];
        }
    }

public:
    void mergeSort(int arr[], int l, int r)
    {
        if (l >= r)
            return;
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
};

//{ Driver Code Starts.

int main()
{
    int n, T, i;

    scanf("%d", &T);

    while (T--)
    {

        scanf("%d", &n);
        int arr[n + 1];
        for (i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        Solution ob;
        ob.mergeSort(arr, 0, n - 1);
        printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends1