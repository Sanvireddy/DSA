#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n == 1)
        return 0;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return 0;
    return 1;
}

vector<bool> better(int n)
{
    vector<bool> v(n + 1, 1);
    if (n >= 2)
        v[0] = v[1] = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (isPrime(i))
        {
            for (int j = 2 * i; j <= n; j += i)
            {
                v[j] = 0;
            }
        }
    }
    return v;
}
int main()
{
    vector<bool> v;
    int n = 7;
    v = better(n);
    for (int i = 0; i <= n; i++)
        if (v[i])
            cout << i << " ";
    cout << endl;
    return 0;
}