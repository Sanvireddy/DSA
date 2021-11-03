#include <bits/stdc++.h>
using namespace std;
int nchoc(int B, vector<int> &A)
{
    if (B == 0 || A.size() == 0)
        return 0;
    map<int, int> m;
    long long int cnt = 0;
    for (int i = 0; i < A.size(); i++)
    {
        m[A[i]]++;
    }
    while (B && !m.empty())
    {
        auto it = m.rbegin();
        int k = it->first;
        cnt = ((cnt % 1000000007) + (k % 1000000007)) % 1000000007;
        m[k]--;
        if (m[k] == 0)
        {
            auto itr = m.end();
            itr--;
            m.erase(itr);
        }
        if ((k / 2) > 0)
            m[k / 2]++;
        B--;
    }
    return cnt % 1000000007;
}
int main()
{
    return 0;
}