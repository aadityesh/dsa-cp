#include <bits/stdc++.h>
using namespace std;

class Add
{
public:
    int sum(int a, int b)
    {
        return a + b;
    }

    // ERROR - cannot overload functions
    // with just different return type

    // void sum(int a, int b)
    // {
    //     // return a + b;
    //     cout << a << b << endl;
    // }

    double sum(double a, double b)
    {
        return a + b;
    }

    int sum(int a, int b, int c)
    {
        return a + b + c;
    }
};

int main()
{
    Add obj;
    cout << obj.sum(3, 4) << endl;
    cout << obj.sum(3.25, 4.8) << endl;
    cout << obj.sum(3, 4, 5) << endl;

    return 0;
}