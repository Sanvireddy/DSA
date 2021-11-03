#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
    unordered_map<int, pair<int, list<int>::iterator>> m;
    list<int> l;
    int cap;
    LRUCache(int capacity)
    {
        m.clear();
        l.clear();
        cap = capacity;
    }

    int get(int key)
    {
        auto it = m.find(key);
        if (it == m.end())
            return -1;
        auto itr = m[key].second;
        int val = m[key].first;
        l.erase(itr);
        l.push_front(key);
        m[key] = {val, l.begin()};
        return val;
    }

    void put(int key, int value)
    {
        auto it = m.find(key);
        if (it != m.end())
        {
            auto itr = m[key].second;
            l.erase(itr);
            l.push_front(key);
            m[key] = {value, l.begin()};
            return;
        }
        if (m.size() == cap)
        {
            int last = l.back();
            l.pop_back();
            l.push_front(key);
            m.erase(last);
            m[key] = {value, l.begin()};
        }
        else
        {
            l.push_front(key);
            m[key] = {value, l.begin()};
        }
        return;
    }
};
int main()
{
    return 0;
}