#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > anagrams(const vector<string> &A)
{
    if (A.size() < 2)
        return {{1}};
    map<vector<int>, vector<int> > m;
    vector<vector<int> > res;
    for (int i = 0; i < A.size(); i++)
    {
        vector<int> v;
        vector<int> v1(26, 0);
        for (int j = 0; j < A[i].size(); j++)
            v1[A[i][j] - 'a']++;
        if (m.find(v1) == m.end())
        {
            v.push_back(i + 1);
            m[v1] = v;
        }
        else
        {
            m[v1].push_back(i + 1);
        }
    }
    for (auto it = m.begin(); it != m.end(); it++)
    {
        res.push_back(it->second);
    }
    return res;
}
int main()
{
    vector<string> v;
    v.push_back("cat");
    v.push_back("dog");
    v.push_back("god");
    v.push_back("tca");
    vector<vector<int> > p;
    p = anagrams(v);
    for (int i = 0; i < p.size(); i++)
    {
        for (int j = 0; j < p[0].size(); j++)
            cout << p[i][j] << endl;
    }
    return 0;
}