#include <bits/stdc++.h>
using namespace std;

void brute(int n)
{
    int size = n + 1;
    vector<int> primes(n + 1, 1);

    for (int i = 2; i < size; i++)
    {
        if (primes[i] == 1)
        {
            for (int j = i * 2; j < size; j += i)
            {
                primes[j] = 0;
            }
        }
    }

    for (int i = 2; i < size; i++)
    {
        if (primes[i] == 1)
        {
            cout << i << " ";
        }
    }

    cout << endl;
}

void optimal(int n)
{
    int size = sqrt(n + 1);
    vector<int> primes(n + 1, 1);

    for (int i = 2; i <= size; i++)
    {
        if (primes[i] == 1)
        {
            for (int j = i * i; j < n + 1; j += i)
            {
                primes[j] = 0;
            }
        }
    }

    for (int i = 2; i < n + 1; i++)
    {
        if (primes[i] == 1)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main()
{

    brute(30);
    optimal(30);

    return 0;
}