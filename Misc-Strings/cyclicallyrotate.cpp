#include <bits/stdc++.h>
using namespace std;
#define f(i, n) for (int i = 0; i < n; i++)

int main()
{

    int n, result = 0;
    cin >> n;
    string s;
    cin >> s;
    map<string, int> m;
    f(i, s.size() - 1)
    {
        m[s[i] + s[i + 1]]++;
    }
    for (auto it = m.begin(); it != m.end(); it++)
        m[it->] cout << result << endl;
    return 0;
}
