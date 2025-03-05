#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void combinations(vector<vector<int>> &res, vector<int> temp,
                      vector<int> &input, int target, int sum, int ind)
    {
        if (sum == target)
        {
            res.push_back(temp);
            return;
        }

        if (ind == input.size() || sum > target)
        {
            return;
        }

        sum += input[ind];
        temp.push_back(input[ind]);
        combinations(res, temp, input, target, sum, ind + 1);

        sum -= input[ind];
        temp.pop_back();

        while (ind + 1 < input.size() && input[ind] == input[ind + 1])
            ind++;

        combinations(res, temp, input, target, sum, ind + 1);
    }

    void iterativeCombinations(vector<vector<int>> &res, vector<int> temp,
                               vector<int> &input, int target, int sum, int ind)
    {

        if (sum == target)
        {
            res.push_back(temp);
            return;
        }

        for (int j = ind; j < input.size(); j++)
        {

            if (j > ind && input[j] == input[j - 1])
                continue;

            if (sum + input[j] > target)
            {
                break;
            }

            sum += input[j];
            temp.push_back(input[j]);

            iterativeCombinations(res, temp, input, target, sum, j + 1);

            sum -= input[j];
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &input, int target)
    {
        int ind = 0;
        int sum = 0;
        vector<vector<int>> res;
        vector<int> temp;
        sort(input.begin(), input.end());
        combinations(res, temp, input, target, sum, ind);
        // iterativeCombinations(res, temp, input, target, 0, 0);
        return res;
    }
};
int main()
{
    int n = 5;
    // cin >> n;
    vector<int> a = {2, 5, 2, 1, 2};
    vector<int> temp;
    vector<vector<int>> res;

    Solution obj;

    res = obj.combinationSum(a, n);
    for (auto vec : res)
    {
        for (int i : vec)
            cout << i << " ";

        cout << endl;
    }

    return 0;
}