#include <bits/stdc++.h>
using namespace std;

int power(int a, int b)
{
    if (b == 0)
        return 1;

    int temp = power(a, b / 2);

    if (b % 2 != 0)
        return a * temp * temp;
    else
        return temp * temp;
}

int count(int n)
{
    int no_of_odd = n / 2;
    int no_of_even = (n + 1) / 2;

    return power(4, no_of_odd) * power(5, no_of_even);
}

int main()
{
    int n;
    cin >> n;
    cout << count(n) << endl;

    return 0;
}