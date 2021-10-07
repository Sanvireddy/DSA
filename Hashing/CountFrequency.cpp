#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second

int main()
{
    int n;
    cin >> n;
    vi a(6);
    map<int, int> m;
    rep(i, 0, 6)
    {
        cin >> a[i];
        m[a[i]]++;
    }
    map<int, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        cout << it->ff << " " << it->ss << endl;
    }

    return 0;
}
