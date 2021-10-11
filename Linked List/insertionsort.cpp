#include <bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;
};

ListNode* insertionSortList(ListNode* A) {
    ListNode* node = A;
    while(node!=NULL)
    {
        ListNode* dummy = A;
        while(node->val > dummy->val) dummy=dummy->next;
        int prev = node->val;
        while(dummy!=node)
        {
            int value = dummy->val;
            dummy->val=prev;
            prev=value;
            dummy=dummy->next;
        }
        dummy->val=prev;
        node=node->next;
    }
    return A;
}


int main()
{
    return 0;
}