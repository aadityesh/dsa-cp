#include <bits/stdc++.h>
using namespace std;

void generate(int idx, int sum, int target, vector<int> subset, vector<vector<int>> &res, vector<int> input)
{
    // cout << sum << endl;
    if (idx == input.size())
    {
        if (sum == target)
            res.push_back(subset);
        return;
    }

#This Works
    subset.push_back(input[idx]);
    sum += input[idx];
    generate(idx + 1, sum, target, subset, res, input);

    subset.pop_back();
    sum -= input[idx];
    generate(idx + 1, sum, target, subset, res, input);

#This does NOT Works
    subset.push_back(input[idx]);
    generate(idx + 1, sum + input[idx], target, subset, res, input);

    subset.pop_back();
    sum -= input[idx];
    generate(idx + 1, sum, target, subset, res, input);

    // 3 1 _
}

int main()
{
    vector<vector<int>> res;
    int idx = 0;
    int target = 10;

    vector<int> input = {5, 2, 3, 10, 6, 8};
    vector<int> arr = {};
    generate(0, 0, target, arr, res, input);

    cout << res.size() << endl;
    for (auto i : res)
    {
        cout << "[ ";
        for (auto elem : i)
        {
            cout << elem << " ";
        }
        cout << "]";
        cout << endl;
    }
    return 0;
}