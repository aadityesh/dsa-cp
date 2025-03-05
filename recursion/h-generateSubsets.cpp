#include <bits/stdc++.h>
using namespace std;

class Subsets
{

    vector<vector<int>> res;

public:
    void iterative(vector<int> &input)
    {
        vector<vector<int>> res = {{}};

        for (int &num : input)
        {
            int size = res.size();
            for (int i = 0; i < size; i++)
            {
                vector<int> curr = res[i];
                curr.push_back(num);
                res.push_back(curr);
            }
        }
    }

    void dfs(int idx, vector<int> temp, vector<int> &input)
    {
        if (idx == input.size())
        {
            res.push_back(temp);
            return;
        }

        temp.push_back(input[idx]);
        dfs(idx + 1, temp, input);

        temp.pop_back();
        dfs(idx + 1, temp, input);
    }

    void bitManip(vector<int> &input)
    {
        int n = input.size();
        int times = 1 << n;
        for (int i = 0; i < times; i++)
        {
            vector<int> temp;
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    temp.push_back(input[j]);
                }
            }

            res.push_back(temp);
        }

        this->display();
    }

    void display()
    {
        for (auto &i : res)
        {
            if (i.size() == 0)
            {
                cout << "{}" << endl;

                continue;
            }

            for (int &elem : i)
            {
                cout << elem << " ";
            }
            cout << endl;
        }
    }
};

/*
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
}*/

int main()
{
    vector<int> input = {1, 2, 3, 4};
    Subsets obj;
    // obj.iterative(input);
    // obj.dfs(0, {}, input);
    // obj.display();
    obj.bitManip(input);
}