#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned int a = 5;
    unsigned int b = 7;

    cout << "AND: " << (a & b) << endl;
    cout << "OR: " << (a | b) << endl;
    cout << "XOR: " << (a ^ b) << endl;
    cout << "NOT: " << (~a) << endl;

    /*  x * (2^y)        -> left*/
    /*  floor(x / (2^y)) -> right*/

    cout << "RIGHT SHIFT: " << (a >> 1) << endl;
    cout << "LEFT SHIFT: " << (a << 1) << endl;

    cout << ((a&b)^7) << endl;

    return 0;
}