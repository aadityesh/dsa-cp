#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int getSum(int a, int b)
    {

        int l1 = 0, l2 = 0, c = 0, res = 0, num = 0, lastBit;

        while (a || b)
        {

            l1 = a & 1;
            l2 = b & 1;

            lastBit = l1 | l2;
            if (l1 == 1 && l2 == 1)
                lastBit = 0;
            if (l1 == 1 && l2 == 1 && c == 1)
                lastBit = 1;

            cout << lastBit << " ";

            num = num << 1;
            num = num | lastBit;
            res = num | res;

            if (l1 == 1 && l2 == 1)
                c = 1;
            else
                c = 0;

            a = a >> 1;
            b = b >> 1;
        }

        if (c)
        {
            res = res << 1;
            cout << num << endl;
            cout << res << endl;
            // num = num | c;
            res = num | res;
            cout << "AD" << endl;
        }

        return res;
    }
};

int main()
{
    int a, b;
    cin >> a >> b;
    Solution obj;
    cout << obj.getSum(a, b) << endl;

    return 0;
}