#include <bits/stdc++.h>
using namespace std;

int maxp3(vector<int> &A)
{
    signed int m1 = INT_MIN, m2 = INT_MIN, m3 = INT_MIN;
    signed int min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] > m1)
        {
            signed int dum = m1;
            m1 = A[i];
            m3 = m2;
            m2 = dum;
        }
        else if (A[i] > m2)
        {
            m3 = m2;
            m2 = A[i];
        }
        else if (A[i] > m3)
            m3 = A[i];
    }
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] < min1)
        {
            signed int dum = min1;
            min1 = A[i];
            min3 = min2;
            min2 = dum;
        }
        else if (A[i] < min2)
        {
            min3 = min2;
            min2 = A[i];
        }
        else if (A[i] < min3)
            min3 = A[i];
    }
    // cout<<m1<<" "<<m2<<" "<<m3<<endl;
    // cout<<min1<<" "<<min2<<" "<<min3<<endl;
    return max(m1 * m2 * m3, min1 * min2 * m1);
}

int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(4);
    v.push_back(5);
    v.push_back(8);
    v.push_back(5);
    cout << maxp3(v) << endl;
    return 0;
}