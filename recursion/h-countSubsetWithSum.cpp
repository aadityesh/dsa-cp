#include <bits/stdc++.h>
using namespace std;

void countSubsetsWithSumK(int idx, int sum, int target, int &cnt, vector<int> subset, vector<int> input)
{
    // cout << sum << endl;
    if (idx == input.size())
    {
        if (sum == target)
            cnt++;
        return;
    }

    subset.push_back(input[idx]);
    sum += input[idx];
    countSubsetsWithSumK(idx + 1, sum, target, cnt, subset, input);

    subset.pop_back();
    sum -= input[idx];
    countSubsetsWithSumK(idx + 1, sum, target, cnt, subset, input);
}

bool checkSumExists(int idx, int sum, int target,
                    vector<int> input)
{
    // cout << sum << endl;
    if (idx == input.size())
    {
        if (sum == target)
            return 1;

        return 0;
    }

    // #This Works
    /**
     * No need to maintain temp[]/result[[]]
     * We only need to check whether the sum == target or not
     * Pick and choose can be done without temp[]
     * if we don't need the subset values in the end.
     *
     */
    // subset.push_back(input[idx]);
    sum += input[idx]; // 3 + 2
    int L = checkSumExists(idx + 1, sum, target, input);

    // subset.pop_back();
    sum -= input[idx];
    int R = checkSumExists(idx + 1, sum, target, input);

    return L + R;
}

int main()
{
    // vector<vector<int>> res;
    int idx = 0;
    int cnt = 0;
    int target = 10;

    vector<int> input = {5, 2, 3, 10, 6, 8};
    vector<int> arr = {};
    countSubsetsWithSumK(0, 0, target, cnt, arr, input);

    cout << "cnt: " << cnt << endl;
    return 0;
}