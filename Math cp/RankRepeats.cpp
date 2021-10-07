#include <bits/stdc++.h>
using namespace std;
long long int gcdExtended(long long int a, long long int b, long long int *x, long long int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    long long int x1, y1; // To store results of recursive call
    long long int gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

long long int modInverse(long long int b, long long int m)
{
    long long int x, y; // used in extended GCD algorithm
    long long int g = gcdExtended(b, m, &x, &y);

    // m is added to handle negative x
    return (x % m + m) % m;
}
long long int modDivide(long long int a, long long int b, long long int m)
{
    a = a % m;
    long long int inv = modInverse(b, m);

    long long int c = (inv * a) % m;
    return c;
}

long long int factorial(int k)
{
    if (k == 0)
        return 1;
    long long int res = 1;
    for (int i = 1; i <= k; i++)
        res = ((res % 1000003) * (i % 1000003)) % 1000003;
    return res % 1000003;
}

long long int fact(int k, vector<int> &v)
{
    long long int res = 0;
    long long int sum = accumulate(v.begin(), v.end(), 0);
    if (accumulate(v.begin(), v.begin() + k, 0) == 0)
        return 0;
    long long int dummy = factorial(sum - 1);
    for (int i = 0; i < k; i++)
    {
        long long int dum = dummy;
        if (!v[i])
        {
            for (int j = 0; j < v.size(); j++)
            {
                if (i != j)
                    dum = modDivide(dum, factorial(v[j]), 1000003);
                else
                    dum = modDivide(dum, factorial(v[j] - 1), 1000003);
            }
            if (dum != dummy)
                res = ((res % 1000003) + (dum % 1000003)) % 1000003;
        }
    }
    return res % 1000003;
}

int findRank(string A)
{
    int res = 0, n = A.size();
    vector<int> v(52, 0);

    for (int i = 0; i < n; i++)
    {
        if (isupper(A[i]))
            v[A[i] - 'A']++;
        else
            v[A[i] - 'a' + 26]++;
    }
    for (int i = 0; i < n; i++)
    {
        int t = islower(A[i]) ? (A[i] - 'a' + 26) : (A[i] - 'A');
        res = ((res % 1000003) + (fact(t, v) % 1000003)) % 1000003;
        v[t]--;
    }
    return (res + 1) % 1000003;
}

int main()
{
    string A = "baaccb";
    cout << findRank(A) << endl;
    return 0;
}