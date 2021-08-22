#include <bits/stdc++.h>

using namespace std;

class Queue
{
public:
    stack<int> s1, s2;
    void enq(int key)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(key);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int deq()
    {
        if (s1.empty())
            return 0;
        else
        {
            int x = s1.top();
            s1.pop();
            return x;
        }
    }
};

int main()
{
    Queue q;
    q.enq(1);
    q.enq(2);
    q.enq(9);

    cout << q.deq() << endl;
    cout << q.deq() << endl;
    cout << q.deq() << endl;
    return 0;
}