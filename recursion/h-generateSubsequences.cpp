#include <bits/stdc++.h>
using namespace std;

void helper(int idx, string curr, string input, vector<string> &res)
{

    if (idx == input.size())
    {
        if (curr.size() > 0)
            res.push_back(curr);

        return;
    }

    curr.push_back(input[idx]);
    helper(idx + 1, curr, input, res);

    curr.pop_back();
    helper(idx + 1, curr, input, res);
}

vector<string> subsequences(string str)
{
    vector<string> res;
    string curr;
    helper(0, curr, str, res);
    // cout << res.size() << endl;
    return res;
}

int main()
{
    string s;
    cin >> s;
    vector<string> res = subsequences(s);

    for (auto i : res)
    {
        for (auto elem : i)
        {
            cout << elem << " ";
        }
        cout << endl;
    }
    int x = 1'000'000'000;
    return 0;
}