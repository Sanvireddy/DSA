#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &A, int B)
{
    if (B == 0 || A.size() == 0)
        return 0;
    map<int, int> m;
    int cnt = 0;
    for (int i = 0; i < A.size(); i++)
    {
        m[A[i]]++;
    }
    while (B && !m.empty())
    {
        auto it = m.rbegin();
        int k = it->first;
        cnt += k;
        m[k]--;
        if (m[k] == 0)
        {
            auto itr = m.end();
            itr--;
            m.erase(itr);
        }
        if (k > 1)
            m[k - 1]++;
        B--;
    }
    return cnt;
}
int main()
{
    return 0;
}