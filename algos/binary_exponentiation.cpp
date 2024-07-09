#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL pow(LL x, LL n)
{
    LL result = 1;
    while (n)
    {
        if (n % 2 == 1)
            result *= x;
        x = x * x;
        n = n / 2;
    }

    return result;
}

LL recursive(LL x, LL n)
{

    if (n == 0)
        return 1;

    int temp = recursive(x, n / 2);

    if (n & 1) // true when odd
    {
        return x * temp * temp;
    }
    else
    {
        return temp * temp;
    }
}

int main()
{
    LL x, n;
    cin >> x >> n;
    cout << pow(x, n) << endl;
    cout << recursive(x, n) << endl;

    return 0;
}