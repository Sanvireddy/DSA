#include <bits/stdc++.h>
using namespace std;

string s;
int main()
{
    vector<int> V(502, -1);
    vector<vector<int>> t(502, V);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            cout << t[i][j] << " ";
    }
    return 0;
}
