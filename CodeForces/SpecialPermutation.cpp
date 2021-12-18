#include <bits/stdc++.h>
using namespace std;
vector<int> find(int n, int a, int b)
{
    vector<int> pref, suf;
    vector<int> res;
    if(a>b)
    {if(a-b>1) return res;
    else
    {
        if(a!=(n/2)+1) return res;
        while(a<=n)
        {
            res.push_back(a++);
        }
        while(b>0)
        res.push_back(b--);
        return res;
    }
    }
    int i = b + 1, half = n / 2;
    int s1 = 1, s2 = 1;
    pref.push_back(a);
    suf.push_back(b);
    while (i <= n)
    {
        s1++;
        pref.push_back(i);
        i++;
    }
    if (s1 > half)
        return res;
    int j = a-1;
    while (j >0)
    {
        suf.push_back(j);
        j--;
        s2++;
    }
    if (s2 > half)
        return res;
    while (s1 < half)
    {
        pref.push_back(a+1);
        a++;
        s1++;
    }
    a++;
    while (s2 < half && a < b)
    {
        suf.push_back(a);
        s2++;
        a++;
    }
    
    res.insert(res.begin(), pref.begin(), pref.end());
    res.insert(res.end(), suf.begin(), suf.end());
    return res;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> v;
        v = find(n, a, b);
        if (v.size() != n)
            cout << -1;
        else
        {
            for (int i = 0; i < n; i++)
            {
                cout << v[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}