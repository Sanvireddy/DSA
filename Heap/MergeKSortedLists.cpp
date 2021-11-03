#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    ListNode *next;
    int val;
    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};
ListNode *mergeKLists(vector<ListNode *> &A)
{
    map<int, int> m;
    for (int i = 0; i < A.size(); i++)
    {
        ListNode *node = A[i];
        while (node)
        {
            m[node->val]++;
            node = node->next;
        }
    }
    auto it = m.begin();
    ListNode *n = new ListNode(it->first);
    ListNode *m1 = n;
    it->second--;
    for (auto itr = m.begin(); itr != m.end(); itr++)
    {
        while (itr->second != 0)
        {
            ListNode *nextnode = new ListNode(itr->first);
            itr->second--;
            n->next = nextnode;
            n = n->next;
        }
    }
    return m1;
}
