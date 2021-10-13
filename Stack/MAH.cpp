#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &A)
{
    stack<int> s;
    s.push(0);
    int n = A.size();
    vector<int> left(n, 0);
    vector<int> right(A.size(), A.size() - 1);
    for (int i = 1; i < A.size(); i++)
    {
        while (!s.empty() && A[s.top()] >= A[i])
            s.pop();
        if (!s.empty())
            left[(s.top() + 1)];
        s.push(i);
    }
    stack<int> s1;
    s1.push(n - 1);
    for (int i = n - 2; i >= 0; i--)
    {
        while (!s1.empty() && A[s1.top()] >= A[i])
            s1.pop();
        if (!s1.empty())
            right[i] = (s1.top() - 1);
        s1.push(i);
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = max(res, (right[i] - left[i] + 1) * A[i]);
    }
    return res;
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(4);
    v.push_back(2);
    v.push_back(5);
    v.push_back(6);
    cout << largestRectangleArea(v) << endl;
    return 0;
}