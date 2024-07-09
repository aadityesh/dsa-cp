#include <bits/stdc++.h>
using namespace std;

class Animal
{
public:
    int legs;
    char color;
    void Display()
    {
        cout << "Animal" << endl;
    }
    void setLegs(int x) { this->legs = x; }
    int getLegs() { return this->legs; };
};

class Dog : public Animal
{
};

class Puppy : public Dog
{
};

int main()
{
    Puppy g;
    g.Display();
    return 0;
}