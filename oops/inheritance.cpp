#include <bits/stdc++.h>
using namespace std;

class Human
{
public:
    unsigned int height;
    unsigned int weight;
    unsigned int age;

    int getAge() { return this->age; }
    int getHeight() { return this->height; }
    int getWeight() { return this->weight; }

    void setAge(int x) { this->age = x; }
    void setHeight(int x) { this->height = x; }
    void setWeight(int x) { this->weight = x; }
};

class Male : public Human
{
    string name;

public:
    void setName(string name) { this->name = name; }
    string getName() { return this->name; }
};

int main()
{
    Male obj;

    // INHERITED MEMBERS
    obj.setAge(40);
    obj.setHeight(175);
    obj.setWeight(80);

    cout << "Age (Inherited) : " << obj.age << endl;
    cout << "Height (Inherited) : " << obj.height << endl;
    cout << "Weight (Inherited) : " << obj.weight << endl;

    // SELF MEMBERS
    obj.setName("John Doe");
    cout << "Name: " << obj.getName() << endl;

    return 0;
}