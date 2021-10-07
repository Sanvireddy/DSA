#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, int> a;
    a[1] = 100;
    a[2] = -1;
    a[3] = 20;
    a[1203123] = 9;

    map<char, int> cnt;
    string s = "sanvi reddy";
    for (auto c : s)
        cnt[c]++;
    cout << cnt['a'] << " " << cnt['m'] << endl;
}