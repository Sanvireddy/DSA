#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {9, 56, 21, 32, 6, 41, 52, 40, 11, 30, 5};
    vector<int> sol;
    for (int i = 0; i < v.size(); i++)
    {
        sol.push_back((2 * v[i] + 344) % 11);
    }
    for (int i = 0; i < sol.size(); i++)
        cout << sol[i] << " ";
    return 0;
}