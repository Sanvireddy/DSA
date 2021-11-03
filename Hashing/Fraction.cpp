#include <bits/stdc++.h>
#include <iterator>
using namespace std;

string fract(int num, int denom)
{
    int k = num / denom;
    string s = to_string(k), s1;
    int rem = num % denom;
    if (rem == 0)
        return s;
    s += ".";
    map<int, int> m;
    bool b = 0;
    while (rem != 0 && !b)
    {
        b = 1;
        rem *= 10;
        s1 += to_string(rem / denom);
        rem = rem % denom;
        m[rem]++;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (it->second % 2 != 0)
                b = 0;
        }
    }
    if (rem != 0)
    {
        s += "(";
        for (int i = 0; i < s1.size() / 2; i++)
        {
            s += s1[i];
        }
        s += ")";
        return s;
    }
    for (int i = 0; i < s1.size(); i++)
    {
        s += s1[i];
    }
    return s;
}
int main()
{
    int num, denom;
    cin >> num >> denom;
    //cout << fract(num, denom) << endl;
    double fractio = num / double(denom);
    cout << fractio << endl;
    string s=to_string(fractio-(num/denom));
    unordered_map<char,int> mp;
    for(int i=0;i<s.size();i++)
    {
        mp[s[]]
    }
    return 0;
}