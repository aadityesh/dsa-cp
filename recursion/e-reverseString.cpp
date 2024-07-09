#include <bits/stdc++.h>
using namespace std;

void reverse(int n, string s)
{
    if (n < 0)
        return;
    cout << s[n];
    reverse(n - 1, s);
}
void reverseStr(int i, int j, string &s)
{
    if (i >= j)
        return;
    swap(s[i], s[j]);
    reverseStr(i + 1, j - 1, s);
}

int main()
{
    string s;
    cin >> s;

    int n = s.length();
    reverse(n - 1, s);
    cout << endl;

    int i = 0;
    int j = n - 1;
    reverseStr(i, j, s);
    cout << s << " ";

    return 0;
}