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

int main()
{
    int a, b;
    cin >> a >> b;
    cout << power(a, b) << endl;

    return 0;
}