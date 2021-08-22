#include <bits/stdc++.h>
using namespace std;

//Method -1: recursive
//TC: exponential
unsigned long int catalanR(int n)
{
    if (n <= 1)
        return 1;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += (catalanR(i) * catalanR(n - i - 1));
    }
    return res;
}

//method-2: dp
//TC: O(n^2)
unsigned long int CatalanDP(int n)
{
    unsigned long int catalan[n + 1];
    catalan[0] = 1;
    catalan[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        catalan[i] = 0;
        for (int j = 0; j < i; j++)
            catalan[i] += (catalan[j] * catalan[i - j - 1]);
    }
    return catalan[n];
}

unsigned long int factorial(int n)
{
    if (n <= 1)
        return 1;
    int res = 1;
    for (int i = 1; i <= n; i++)
        res = res * i;
    return res;
}

unsigned long int catalanBC(int n)
{
    unsigned long int num = (factorial(2 * n));
    unsigned long int denom = (factorial(n + 1) * factorial(n));
    num /= denom;
    return num;
}

int main()
{
    int n;
    cin >> n;
    cout << n << "th catalan number: " << catalanR(n) << endl;
    cout << n << "th catalan number: " << CatalanDP(n) << endl;
    cout << n << "th catalan number: " << catalanBC(n) << endl;
    cout << n << "th catalan number: " << factorial(n) << endl;
    return 0;
}