#include <bits/stdc++.h>
using namespace std;

int maxPossible(int wt[], int n, int sum)
{
    int t[n + 1][sum + 1];
    t[0][0] = 0;
    for (int i = 1; i < sum + 1; i++)
        t[0][i] = INT_MIN;
    for (int i = 1; i < n + 1; i++)
        t[i][0] = 0;
    for (int i = 1; i < sum + 1; i++)
    {
        if (i % (wt[0]) == 0)
            t[1][i] = i / wt[0];
        else
            t[1][i] = INT_MIN;
    }
    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (wt[i - 1] <= j)
                t[i][j] = max(t[i - 1][j], 1 + t[i][j - wt[i - 1]]);
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][sum];
}

int main()
{
    int n;
    int a, b, c;
    cin >> n >> a >> b >> c;
    int wt[] = {a, b, c};
    cout << maxPossible(wt, 3, n) << endl;
    return 0;
}