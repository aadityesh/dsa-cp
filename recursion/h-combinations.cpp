#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void combinations(vector<vector<int>> &res, vector<int> temp,
                      vector<int> &input, int target, int sum, int ind)
    {

        if (ind == input.size() || sum > target)
        {
            return;
        }

        if (sum == target)
        {
            res.push_back(temp);
            return;
        }

        sum += input[ind];
        temp.push_back(input[ind]);
        combinations(res, temp, input, target, sum, ind);

        sum -= input[ind];
        temp.pop_back();

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
            if (sum + input[j] > target)
            {
                break;
                ;
            }

            sum += input[j];
            temp.push_back(input[j]);
            iterativeCombinations(res, temp, input, target, sum, j);

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
        // combinations(res, temp, input, target, sum, ind);
        sort(input.begin(), input.end());
        iterativeCombinations(res, temp, input, target, 0, 0);
        return res;
    }
};
int main()
{
    int n = 7;
    // cin >> n;
    vector<int> a = {2, 3, 6, 7};
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