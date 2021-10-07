#include <bits/stdc++.h>
using namespace std;

int minCoins(int coins[], int M, int V)
{
    int t[M + 1][V + 1];
    t[0][0] = INT_MAX - 1;
    for (int i = 1; i < M + 1; i++)
        t[i][0] = 0;
    for (int i = 1; i < V + 1; i++)
        t[0][i] = INT_MAX - 1;
    for (int i = 1; i < V + 1; i++)
    {
        if (i % coins[0] == 0)
            t[1][i] = i / coins[0];
        else
            t[1][i] = INT_MAX - 1;
    }
    for (int i = 2; i < M + 1; i++)
    {
        for (int j = 1; j < V + 1; j++)
        {
            if (coins[i - 1] <= j)
                t[i][j] = min(t[i - 1][j], 1 + t[i][j - coins[i - 1]]);
            else
                t[i][j] = t[i - 1][j];
        }
    }
    if (t[M][V] >= INT_MAX - 1)
        return -1;
    else
        return t[M][V];
}

int main()
{
    int M = 3, V = 30;
    int coins[] = {3, 28, 2};
    cout << minCoins(coins, M, V) << endl;
    return 0;
}