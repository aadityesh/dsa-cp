#include <bits/stdc++.h>
using namespace std;

class Sub
{
    int a;
    int b;

public:
    Sub(int a, int b) : a(a), b(b) {}
    int sum()
    {
        return this->a + this->b;
    }

    int operator+(Sub &obj)
    {
        return this->a - obj.a;
    }

    void operator()()
    {
        cout << "Parenthesis!" << endl;
    }
};

int main()
{
    Sub obj1(5, 2);
    Sub obj2(15, 4);
    cout << obj1.sum() << endl;
    cout << obj1 + obj2 << endl;
    obj1();
    return 0;
}