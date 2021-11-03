#include <bits/stdc++.h>
using namespace std;

vector<int> equal(vector<int> &A)
{
    int n = A.size();
    vector<int> res;
    if (n < 4)
        return res;
    for (int i = 0; i < (n - 1); i++)
    {
        for (int j = i + 1; j < (n); j++)
        {
            for (int k = i + 1; k < n; k++)
            {
                for (int p = k + 1; p < n; p++)
                {
                    if (j != p && j != k)
                    {
                        if ((A[i] + A[j]) == (A[k] + A[p]))
                        {
                            res.push_back(i);
                            res.push_back(j);
                            res.push_back(k);
                            res.push_back(p);
                            return res;
                        }
                    }
                }
            }
        }
    }
    return res;
}
int main()
{
    return 0;
}