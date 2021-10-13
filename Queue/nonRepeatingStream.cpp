#include <bits/stdc++.h>
using namespace std;

string solve(string A)
{
    vector<int> v(26, 0);
    queue<char> q;
    string res;
    for (int i = 0; i < A.size(); i++)
    {
        v[A[i] - 'a']++;
        q.push(A[i]);
        while (!q.empty() && v[q.front() - 'a'] >= 2)
            q.pop();

        if (q.empty())
            res += '#';
        else
            res += q.front();
    }
    return res;
}

int main()
{
    string s = "jyhrcwuengcbnuchctluxjgtxqtfvrebveewgasluuwooupcyxwgl";
    cout << solve(s) << endl;
    return 0;
}