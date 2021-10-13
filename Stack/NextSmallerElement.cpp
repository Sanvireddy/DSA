#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int> &A)
{
    vector<int> g(A.size(), -1);
    stack<int> s;
    s.push(0);
    for (int i = 1; i < A.size(); i++)
    {
        while (!s.empty() && A[s.top()] >= A[i])
            s.pop();
        if (s.empty())
            g[i] = -1;
        else
            g[i] = A[s.top()];
        s.push(i);
    }
    return g;
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(5);
    v.push_back(3);
    v.push_back(5);
    v.push_back(8);
    vector<int> g;
    g = prevSmaller(v);
    for (int i = 0; i < g.size(); i++)
        cout << g[i] << " ";
    cout << endl;
    return 0;
}