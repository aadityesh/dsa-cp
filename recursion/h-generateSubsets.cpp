#include <bits/stdc++.h>
using namespace std;

void generate(int idx, vector<int> subset, vector<vector<int>> &res, vector<int> input)
{

    if (idx == input.size())
    {
        res.push_back(subset);
        return;
    }

    subset.push_back(input[idx]);
    generate(idx + 1, subset, res, input);

    subset.pop_back();
    generate(idx + 1, subset, res, input);

    // 3 1 _
}

int main()
{
    vector<vector<int>> res;
    int idx = 0;

    vector<int> input = {3, 1, 2};
    vector<int> arr = {};
    generate(0, arr, res, input);

    for (auto i : res)
    {
        for (auto elem : i)
        {
            cout << elem << " ";
        }
        cout << endl;
    }
    return 0;
}