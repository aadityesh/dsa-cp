#include <bits/stdc++.h>
using namespace std;

class A
{
public:
    void DisplayA() { cout << "A" << endl; }
    void disp() { cout << "in A" << endl; }
};

class B
{
public:
    void DisplayB() { cout << "B" << endl; }
    void disp() { cout << "in B" << endl; }
};

class C : public A, public B
{
};

int main()
{
    C obj1;
    obj1.DisplayA();
    obj1.DisplayB();
    obj1.A::disp();
    obj1.B::disp();

    return 0;
}