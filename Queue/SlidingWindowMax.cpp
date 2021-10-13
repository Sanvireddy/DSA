#include <bits/stdc++.h>
using namespace std;

vector<int> slidingmax(vector<int> p, int b)
{
    vector<int> v;
    deque<int> d;
    for (int i = 0; i < b; i++)
    {
        while (!d.empty() && p[i] > p[d.back()])
            d.pop_back();
        d.push_back(i);
    }
    for (int i = b; i < p.size(); i++)
    {
        v.push_back(p[d.front()]);
        while (!d.empty() && d.front() <= (i - b))
            d.pop_front();
        while (!d.empty() && p[i] > p[d.back()])
            d.pop_back();
        d.push_back(i);
    }
    v.push_back(p[d.front()]);
}

int main()
{
    int arr[] = {1, -2, 3, -5, 1, 9};
    vector<int> v;
    v.push_back(1);
    v.push_back(0);
    v.push_back(2);
    v.push_back(4);
    v.push_back(-1);
    v.push_back(-9);
    v.push_back(10);
    vector<int> p = slidingmax(v, 3);
    for (int i = 0; i < p.size(); i++)
        cout << p[i] << " ";
    cout << endl;
    return 0;
}