#include <bits/stdc++.h>
using namespace std;

bool comp(string s1, string s2)
{
    for (int i = 0; i < min(s1.size() - 1, s2.size() - 1); i++)
    {
        if (s1[i] == s2[i])
        {
            return s1.substr(i + 1, s1.size() - i - 1) < s2.substr(i + 1, s1.size() - i - 1);
        }
    }
    if (s1.size() > s2.size())
    {
        if (s1[s2.size()] == '0')
    }

    return s1 < s2;
}
int main()
{
    vector<string> v;
    string s;
    v = {"9", "98", "12", "1", "10", "4", "8", "97", "110"};
    sort(v.begin(), v.end(), comp);
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        s += v[i];
        cout << v[i] << endl;
    }
    cout << s << endl;

    return 0;
}