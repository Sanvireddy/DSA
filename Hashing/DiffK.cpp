#include <bits/stdc++.h>
using namespace std;

int diffPossible(const vector<int> &A, int k)
{
    map<int, int> m;
    for (int i = 0; i < A.size(); i++)
        m[A[i]]++;
    if (k == 0)
    {
        for (int i = 0; i < A.size(); i++)
        {
            {
                if (m[A[i]] > 1)
                    return 1;
                return 0;
            }
        }
    }
    for (int i = 0; i < A.size(); i++)
    {
        if (m.find(A[i] + k) != m.end() || m.find(A[i] - k) != m.end())
            return 1;
    }
    return 0;
}

int main()
{
    vector<int> v;
    v.push_back(9);
    v.push_back(0);
    v.push_back(9);
    v.push_back(2);
    v.push_back(3);
    cout << diffPossible(v, 0) << endl;
    return 0;
}