// #include <bits/stdc++.h>
// using namespace std;

// int partition(vector<int> &arr, int low, int high)
// {
//     int pivot = arr[low];
//     int i = low;
//     int j = high;

//     while (i < j)
//     {
//         while (arr[i] <= pivot && i <= high - 1)
//         {
//             i++;
//         }

//         while (arr[j] > pivot && j >= low + 1)
//         {
//             j--;
//         }
//         if (i < j)
//             swap(arr[i], arr[j]);
//     }
//     swap(arr[low], arr[j]);
//     for (int i = low; i <= high; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << "\n";
//     return j;
// }

// void qs(vector<int> &arr, int low, int high)
// {
//     if (low < high)
//     {
//         int pIndex = partition(arr, low, high);
//         cout << "*" << pIndex << low << high << "\n";
//         qs(arr, low, pIndex - 1);
//         qs(arr, pIndex + 1, high);
//     }
// }

// vector<int> quickSort(vector<int> arr)
// {
//     qs(arr, 0, arr.size() - 1);
//     return arr;
// }

// int main()
// {
//     vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
//     int n = arr.size();
//     cout << "Before Using quick Sort: " << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     arr = quickSort(arr);
//     cout << "After Using quick sort: " << "\n";
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << "\n";
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(string &curr, string &t, unordered_map<char, int> &tmap)
    {

        unordered_map<char, int> umap;
        for (char i : curr)
        {
            umap[i]++;
        }

        for (char i : t)
        {
            if (curr.find(i) == string::npos)
                return false;
            if (umap[i] < tmap[i])
                return false;
        }
        return true;
    }

    string minWindow(string s, string t)
    {

        if (s == t)
            return s;

        int len1 = s.length();
        int len2 = t.length();

        string res = "";
        int minLength = 0;

        if (len2 > len1)
            return res;

        unordered_map<char, int> tmap;
        for (char i : t)
        {
            tmap[i]++;
        }

        for (int i = 0; i < len1; i++)
        {
            for (int j = i; j < len1; j++)
            {

                string curr = s.substr(i, (j - i) + 1);
                // cout << curr;

                if (check(curr, t, tmap))
                {

                    if (minLength == 0)
                    {
                        res = curr;
                        minLength = curr.length();
                    }

                    if (minLength > curr.length())
                    {
                        res = curr;
                        minLength = curr.length();
                    }
                }
                // cout << " " << res << endl;
            }
        }

        return res;
    }
};

int main()
{
    string s, t;
    cin >> s >> t;

    Solution obj;
    cout << obj.minWindow(s, t) << endl;
    return 0;
}