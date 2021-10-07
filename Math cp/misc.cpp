#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n, k, l;
    cin >> n;
    vector<int> v;
    while (n--)
    {
        cin >> k;
        v.push_back(k);
    }
    int maxi = *max_element(v.begin(), v.end());
    int maxim = INT_MIN;
    for (int i = 0; i < v.size(); i++)
    {
        if (maxi % v[i] != 0)
        {
            maxim = max(maxim, v[i]);
        }
    }
    if (maxim == INT_MIN)
    {
        if (v.size() % 2 == 0)
            maxim = maxi;
        else
            maxim = 1;
    }
    cout << maxi << " " << maxim << endl;
    return 0;
}