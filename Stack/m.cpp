#include <bits/stdc++.h>
#include <stack>
using namespace std;

int main()
{
    int prices[] = {8, 4, 6, 2, 3};
    int n = sizeof(prices) / sizeof(prices[0]);
    for (int i = 0; i < (n - 1); i++)
    {
        int j = i + 1;
        while ((j < n) && (prices[j] > prices[i]))
            j++;
        if (prices[j] <= prices[i])
            prices[i] -= prices[j];
        cout << prices[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << prices[i] << " ";
    }
    return 0;
}
