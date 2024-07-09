#include <bits/stdc++.h>
using namespace std;

int helper(int i, int res, int sign, string s)
{

    if (i >= s.length() || s[i] < '0' || s[i] > '9')
        return res;

    int digit = s[i] - '0'; // 4

    if (res > (INT_MAX / 10) || ((res * 10) > (INT_MAX - digit)))
        return sign > 0 ? INT_MAX : INT_MIN;

    res = res * 10 + digit;

    return helper(i + 1, res, sign, s);
}

int stringToInteger(string s)
{

    int i = 0;
    int sign = 1;

    while (s[i] == ' ')
    {
        i++;
    }

    if (s[i] == '-')
    {
        sign = -1;
        i++;
    }

    if (s[i] == '+')
    {
        i++;
    }
    cout << i << endl;
    return helper(i, 0, sign, s);
}

int main()
{
    string s;
    getline(cin, s);

    cout << s << endl;
    cout << stringToInteger(s) << endl;

    return 0;
}