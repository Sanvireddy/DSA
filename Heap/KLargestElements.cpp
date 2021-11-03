#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A, int K)
{
    map<int, int> m;
    vector<int> v;
    for (int i = 0; i < A.size(); i++)
    {
        m[A[i]]++;
    }
    auto it = m.rbegin();
    while (K && !m.empty())
    {
        if (it->second != 0)
        {
            v.push_back(it->first);
            int k = it->first;
            m[k]--;
            K--;
        }
        else
            it++;
    }
    return v;
}
int main()
{
    return 0;
}