#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    for (int i = 3; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

void primefactor(int n)
{
    if (n == 1)
    {
        cout << "No prime factors" << endl;
        return;
    }
    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i) && n % i == 0)
        {
            int cnt = 0;
            while (n % i == 0)
            {
                n /= i;
                cnt++;
            }
            cout << "( " << i << " , " << cnt << " )" << endl;
        }
    }
}

void sieve(int n)
{
    vector<int> v(1000001, -1);
    v[0] = 1;
    v[1] = 1;
    int maxN = 1000001;
    for (int i = 2; i <= maxN; i++)
    {
        if (v[i] == -1)
        {
            for (int j = i; j <= maxN; j += i)
            {
                v[j] = i;
            }
        }
    }
    while (n != 1)
    {
        cout << v[n] << endl;
        n = n / v[n];
    }
}

int main()
{
    int n = 2 * 3 * 5 * 7;
    primefactor(n);
    return 0;
}