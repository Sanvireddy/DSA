#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s;
    //inserting in O(logn)
    s.insert(-1);
    s.insert(9);
    s.insert(5);
    s.insert(4);

    //printing set
    for (auto it : s)
        cout << it << " ";
    cout << endl;

    auto it = s.find(5);
    auto it2 = s.find(10);
    if (it2 == s.end())
    {
        cout << "not present\n";
    }
    else
    {
        cout << "present";
    }

    auto it3 = s.lower_bound(5);  //>=
    auto it4 = s.upper_bound(-1); //<
    if (it4 == s.end())
        cout << "not present" << endl;
    cout << *it3 << " " << *it4;
    s.erase(9);
}