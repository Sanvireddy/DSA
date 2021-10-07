#include <bits/stdc++.h>
using namespace std;

int naive(int base, int n)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
    {
        res = res * base;
    }
    return res;
}

int optimised(int base, int power)
{
    int res = 1;
    while (power != 0)
    {
        if (power % 2 == 0)
        {
            power /= 2;
            base = base * base;
        }
        else
        {
            res = res * base;
            power--;
        }
    }
    return res;
}

int main()
{
    int base = 12, n = 5;
    cout << naive(base, n) << endl;
    cout << optimised(12, 5) << endl;
    cout << pow(12, 5) << endl;
    return 0;
}