#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void helper(vector<string> &res, string &s, int n)
    {

        /*
            # Pop Operation shows backtracking
            # If statements ensure that only valid parentheses is generated
        */
        // cout << "@" << endl;
        if (s.length() == n)
        {
            res.push_back(s);
            return;
        }

        if (s.back() == '0')
        {

            s.push_back('0');
            helper(res, s, n);
            s.pop_back();

            s.push_back('1');
            helper(res, s, n);
            s.pop_back();
        }

        if (s.back() == '1')
        {
            s.push_back('0');
            helper(res, s, n);
            s.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        string curr = "0";
        helper(res, curr, n);
        curr = "1";
        helper(res, curr, n);

        return res;
    }
};

int main()
{
    int n;
    cin >> n;

    Solution obj;
    vector<string> res = obj.generateParenthesis(n);

    for (string i : res)
    {
        cout << i << "\n";
    }

    // string a = "abcd";
    // cout << a.back() << " ";

    return 0;
}