#include <bits/stdc++.h>

using namespace std;

int lcm(int a, int b)
{
    // 5 , 7
    int maxi = max(a, b); // 7
    int mini = min(a, b); // 5

    int res = a * b;
    for (int i = maxi;; i += maxi)
    {
        if (i % mini == 0)
        {
            res = i;
            break;
        }
    }
    // a * b = lcm(a,b) * gcd(a,b)
    return res;
}

int main()
{

    return 0;
}