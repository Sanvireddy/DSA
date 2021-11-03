#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> A, int B)
{
    int cnt = 0, x = 0;
    map<int, int> m;
    for (int i = 0; i < A.size(); i++)
    {
        x = x ^ A[i];
        if (x == B)
            cnt++;
        int y = x ^ B;
        cnt += m[y];
        m[x]++;
    }
    return cnt;
}

int main()
{
    vector<int> v;
    v.push_back(9);
    v.push_back(0);
    v.push_back(9);
    v.push_back(2);
    v.push_back(3);
    cout << solve(v, 3) << endl;
    return 0;
}