#include <bits/stdc++.h>
using namespace std;

bool subsetsum(int arr[], int sum, int n)
{
    int t[n + 1][sum + 1];
    for (int i = 0; i < sum + 1; i++)
        t[0][i] = false;
    for (int i = 0; i < n + 1; i++)
        t[i][0] = true;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= sum)
            {
                t[i][j] = t[i - 1][j] || t[i - 1][j - arr[i - 1]];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][sum];
}

bool equalsum(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    if (sum % 2 != 0)
        return false;
    return subsetsum(arr, sum / 2, n);
}

int main()
{
    int arr[] = {2, 3, 8, 9};
    int sum = 299;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << equalsum(arr, n) << endl;

    return 0;
}