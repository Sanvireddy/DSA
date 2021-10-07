#include <bits/stdc++.h>
using namespace std;

void LPS(vector<int> p, int n, vector<int> lps)
{
    int i = 1;
    int len = 0;
    lps[0] = 0;
    while (i < n)
    {
        if (p[i] == p[len])
        {
            lps[i] = len + 1;
            i++;
            len++;
        }
        else
        {
            if (len != 0)
            {
                lps[i] = lps[i - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}