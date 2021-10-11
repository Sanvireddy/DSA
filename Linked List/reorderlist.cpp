#include <bits/stdc++.h>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x),next(NULL) {}
};


ListNode* reverse(ListNode* A)
{
    if(A==NULL || A->next==NULL) return A;
    ListNode* rest=reverse(A->next);
    A->next->next=A;
    A->next=NULL;
    return rest;   
}


ListNode* reorderList(ListNode* A) {
    if(A==NULL || A->next==NULL || A->next->next==NULL) return A;
    ListNode* res=A;   
    ListNode* prev=A; ListNode* prev2=A;
    ListNode* slow=A->next;ListNode* fast=A->next->next;
    while(fast && fast->next)
    {
        slow=slow->next;fast=fast->next->next;
    }
    ListNode* rev=slow->next;
    slow->next=NULL;
    ListNode* next1; ListNode* next2;
    ListNode* hulu=reverse(rev);
    
    //return hulu;
    while(hulu)
    {
        A=prev;
        prev=A->next;
        A->next=hulu;
        prev2=hulu->next;
        hulu->next=prev;
        hulu=prev2;
    }
    //prev->next=hulu;
    return res;
}
