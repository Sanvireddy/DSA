#include <bits/stdc++.h>
using namespace std;

int KnapSack(int W, int wt[], int val[], int N, int **t)
{

    if (W == 0 || N == 0) //base condition
        return 0;

    if (t[N][W] != -1)
        return t[N][W];

    if (wt[N - 1] <= W)
    {
        t[N][W] = max(val[N - 1] + KnapSack(W - wt[N - 1], wt, val, N - 1, t), KnapSack(W, wt, val, N - 1, t));
        return t[N][W];
    }
    else
    {
        t[N][W] = KnapSack(W, wt, val, N - 1, t);
        return t[N][W];
    }
}

int knapSack(int W, int wt[], int val[], int N)
{
    int **t;
    t = new int *[N + 1];
    for (int i = 0; i < N + 1; i++)
        t[i] = new int[W + 1];
    for (int i = 0; i < N + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
            t[i][j] = -1;
    }
    return KnapSack(W, wt, val, N, t);
}
//Bottom down or Iterative approach

int knapSackIter(int W, int wt[], int val[], int N)
{
    int t[N + 1][W + 1];
    for (int k = 0; k < N + 1; k++)
        t[k][0] = 0;
    for (int k = 0; k < W + 1; k++)
        t[0][k] = 0;
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[N][W];
}

int main()
{
    int n, w;
    cin >> n >> w;
    int val[n];
    int wt[n];
    for (int i = 0; i < n; i++)
        cin >> val[i];

    for (int i = 0; i < n; i++)
        cin >> wt[i];
    cout << knapSack(w, wt, val, n) << endl;
    cout << knapSackIter(w, wt, val, n) << endl;
    return 0;
}