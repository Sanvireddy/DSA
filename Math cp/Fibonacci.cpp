#include <bits/stdc++.h>
using namespace std;

void mul(vector<int> a[2], vector<int> b[2], int dim)
{
    int res[dim][dim];
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < dim; k++)
                res[i][j] += a[i][k] * b[k][j];
        }
    }
    for (int i = 0; i < dim; i++)
        for (int j = 0; j < dim; j++)
            a[i][j] = res[i][j];
}

void power(vector<int> v[2], int dim, int n)
{
    vector<int> I[dim];
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            if (i == j)
                I[i][j] = 1;
            else
                I[i][j] = 0;
        }
    }
    while (n)
    {
        if (n % 2)
        {
            mul(I, v, dim);
            n--;
        }
        else
        {
            mul(v, v, dim);
            n /= 2;
        }
    }
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            v[i][j] = I[i][j];
        }
    }
}

int getfib(int n)
{
    if (n <= 2)
        return 1;
    vector<int> v[2];
    v[0][0] = 0;
    v[0][1] = 1, v[1][0] = 1, v[1][1] = 1;
    power(v, 2, n - 1);
    
    return v[0][0] + v[1][0];
}
int main()
{
    int dim = 2, n;
    cin >> n;
    cout << getfib(n) << endl;
    return 0;
}