// #include <bits/stdc++.h>
// using namespace std;

// class Hero
// {
// public:
//     char *name;
//     int health;
//     char level;
//     static int count;
//     // DEFAULT CONSTRUCTOR

//     Hero()
//     {
//         cout << "Default Constructor" << endl;
//     }
//     // Hero(int a, char b) : health(a), level(b) {}
//     // PARAMETERISED CONSTRUCTOR

//     Hero(char *_name, int health, int level)
//     {
//         name = new char[strlen(_name) + 1];
//         strcpy(name, _name);
//         this->health = health;
//         this->level = level;
//     }

//     // COPY CONSTRUCTOR

//     // Hero(Hero &x) {
//     // char *ch = new char[strlen(x.name) + 1];
//     // strcpy(ch, x.name);
//     // this->health = x.health;
//     // this->level = x.level;
//     // }

//     void print() const
//     {
//         cout << endl;
//         cout << "name: " << name << endl;
//         cout << "health: " << health << endl;
//         cout << "level: " << level << endl;
//         cout << endl;
//     }
//     static void printCount()
//     {
//         cout << count << endl;
//     }
// };

// int Hero ::count = 5;

// int main()
// {
//     Hero a("Jin Kazama", 50, 'A');
//     Hero *b = new Hero;
//     Hero cpy(a);

//     a.print();
//     cpy.print();
//     a.name[0] = 'H';
//     a.print();
//     cpy.print();
//     Hero::printCount();
//     return 0;
// }

// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

string mapDigits(int n)
{
    unordered_map<int, string> umap;
    umap[0] = "Zero";
    umap[1] = "One";
    umap[2] = "Two";
    umap[3] = "Three";
    umap[4] = "Four";
    umap[5] = "Five";
    umap[6] = "Six";
    umap[7] = "Seven";
    umap[8] = "Eight";
    umap[9] = "Nine";

    return umap[n];
}

string sayDigit(string res, int n)
{
    if (n == 0)
        return res;

    res = mapDigits(n % 10) + " " + res;
    n = n / 10;

    return sayDigit(res, n);
}

int fn(int arr[], int n)
{
    if (n == 0 || n == 1)
        return true;

    if (arr[0] > arr[1])
        return false;

    else
        fn(arr + 1, n - 1);
}

int f(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    return (f(n - 1) + f(n - 2));
}

int main()
{

    // for (int i = 1; i <= 8; i++)
    // {
    //     cout << f(i) << " ";
    // }
    string ans = "";
    string res = sayDigit(ans, 412);
    // reverse(res.begin(), res.end());
    for (auto i : res)
        cout << i << " ";
    return 0;
}