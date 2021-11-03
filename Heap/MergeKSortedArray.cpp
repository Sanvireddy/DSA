#include <bits/stdc++.h>
using namespace std;
vector<int> mergetwo(vector<int> v1, vector<int> v2)
{
    if (v1.size() == 0)
        return v2;
    if (v2.size() == 0)
        return v1;
    int i = 0, j = 0;
    vector<int> v;
    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] > v2[j])
        {
            v.push_back(v2[j]);
            j++;
        }
        else
        {
            v.push_back(v1[i]);
            i++;
        }
    }
    while (i < v1.size())
    {
        v.push_back(v1[i]);
        i++;
    }
    while (j < v2.size())
    {
        v.push_back(v2[j]);
        j++;
    }
    return v;
}
vector<int> solve(vector<vector<int>> &A)
{
    vector<int> v;
    for (int i = 0; i < A.size(); i++)
    {
        v = mergetwo(A[i], v);
    }
    return v;
}
int main()
{
    return 0;
}