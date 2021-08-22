#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    long long int n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        long long int res;
        double a = n / 6.0, b = n / 8.0, c = n / 10.0;
        res = min(ceil(a) * 15, ceil(b) * 20);
        res = res < ceil(c) * 25 ? res : (ceil(c) * 25);
        cout << res << endl;
    }
    return 0;
}