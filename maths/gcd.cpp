#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    // if (b == 0)
    //     return a;

    // return gcd(b, a % b);

    int mini = min(a, b);
    int res = 1;
    for (int i = 1; i <= mini; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            res = i;
        }
    }
    cout << res << endl;

    // Optimize
    for (int i = 1; i <= mini; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            res = i;
        }
    }
    cout << res << endl;
}

int main()
{
    int a = 27;
    int b = 18;
    cout << gcd(a, b) << endl;
    return 0;
}