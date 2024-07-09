#include <bits/stdc++.h>
/*
 * To include class/functions from other cpp files
 * #include "filename.cpp"
 */
using namespace std;

class A
{
public:
    int health;
    string s;

    void print()
    {
        cout << health << endl;
    }

    int setHealth(int x)
    {
        if (x >= 0)
            health = x;
        else
            cout << "Health cannot be -ve" << endl;
    }

    int getHealth()
    {
        return health;
    }
};

int main()
{
    // static allocation
    A h1;
    h1.getHealth();
    h1.setHealth(10);

    // dynamic allocation
    A *obj = new A;

    /*
    (*obj).getHealth();
    (*obj).setHealth(60);

        or

    */

    obj->getHealth();
    obj->setHealth(75);

    cout << sizeof(h1) << endl;

    return 0;
}