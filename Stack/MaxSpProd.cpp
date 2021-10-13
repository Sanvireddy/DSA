#include <bits/stdc++.h>
using namespace std;

int maxSpecialProduct(vector<int> &A)
{
    if (A.size() <= 2)
        return 0;
    stack<long long int> s;
    s.push(0);
    long long int n = A.size();
    vector<long long int> left(n, 0);
    vector<long long int> right(A.size(), 0);
    for (long long int i = 1; i < A.size(); i++)
    {
        while (!s.empty() && A[s.top()] <= A[i])
            s.pop();
        if (!s.empty())
            left[i] = (s.top());

        s.push(i);
    }
    stack<long long int> s1;
    s1.push(n - 1);
    for (long long int i = n - 2; i >= 0; i--)
    {
        while (!s1.empty() && A[s1.top()] <= A[i])
            s1.pop();
        if (!s1.empty())
            right[i] = (s1.top());
        s1.push(i);
    }
    long long int res = 0;
    for (long long int i = 0; i < n; i++)
    {
        //cout<<right[i]<<" "<<left[i]<<endl;
        res = max(res, (right[i] * left[i]));
    }
    return res % 1000000007;
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);
    v.push_back(4);
    cout << maxSpecialProduct(v) << endl;
    return 0;
}