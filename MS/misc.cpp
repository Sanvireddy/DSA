#include <bits/stdc++.h>
using namespace std;

bool comp(string s1, string s2)
{
    if (s1.size() < s2.size())
        return s1 > s2;
    return s1 < s2;
}

void sol(vector<string> &v)
{
    if (v.size() == 0)
        return;
    if (v[0].size() == v.back().size())
    {
        if (v[0].size() == 1)
        {
            v[0] = "9";
        }
        else
        {
            if (v[0][0] == '9')
            {
                v[0][1] = '9';
            }
            else
            {
                v[0][0] = '9';
            }
        }
        return;
    }
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i].size() < v[i + 1].size())
        {
            v[i + 1][0] = '9';
            break;
        }
    }
    return;
}
int main()
{
    vector<string> v{"02", "0", "2", "1", "92", "93", "98", "97", "99"};
    sort(v.begin(), v.end());
    //sol(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}