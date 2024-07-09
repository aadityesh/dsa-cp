#include <bits/stdc++.h>
using namespace std;

class A
{
    char *name;
    const int constant;
    int a;
    int b;

public:
    // Default Constructor
    // A()
    // {
    //     name = new char[100];
    //     cout << "Default Constructor" << endl;
    // }

    // Compulsory when declaring constant members
    A(int a) : constant(a) {}

    void print() const
    {
        cout << "this cannot modify any data members!" << endl;
    }

    // Parameterised Constructor

    // A(int _a, int _b)
    // {
    //     a = _a;
    //     b = _b;

    // }
    // A(int a, int b)
    // {
    //     this->a = a;
    //     this->b = b;
    // }

    // Copy Constructor

    // A(A &x)
    // {
    //      this->a = x.a;
    //      this->b = x.b;
    // }

    // shallow copy - default copy constructor
    // deep copy
    // A(A &x)
    // {
    //     char *ch = new char[strlen(x.name) + 1];
    //     this->a = x.a;
    //     this->b = x.b;
    // }
};

int main()
{

    return 0;
}