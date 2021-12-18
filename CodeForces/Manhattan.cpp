#include <bits/stdc++.h>
using namespace std;

pair<int,int> find(int x, int y)
{
    int a, b;
    a = x;
    b = (y - x);
    if (b % 2 == 0 && (y >= (b / 2)) && b >= 0)
        return make_pair(a, b / 2);
    b = y;
    a = (x - y);
    if (a % 2 == 0 && (x >= (a / 2)) && a >= 0)
        return make_pair(a / 2, b);
    return make_pair(-1, -1);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        pair<int,int> v;
        v = find(x, y);
        cout << v.first << " " << v.second << endl;
    }
    return 0;
}