#include <bits/stdc++.h>
using namespace std;

class A
{
public:
    void speak()
    {
        cout << "I am A" << endl;
    }
};

class B : public A
{
public:
    void speak()
    {
        cout << "I am B" << endl;
    }
};

int main()
{

    B obj;
    obj.A::speak();
    obj.speak();
    return 0;
}