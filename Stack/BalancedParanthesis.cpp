#include <bits/stdc++.h>
using namespace std;

int solve(string A)
{
    stack<char> s;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == '(')
            s.push(A[i]);
        else
        {
            if (!s.empty() && s.top() == '(')
                s.pop();
            else
                return 0;
        }
    }
    if (s.empty())
        return 1;
    return 0;
}


int main()
{
    string s = "((())())())";
    cout << solve(s) << endl;
    return 0;
}