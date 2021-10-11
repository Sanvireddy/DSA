#include <bits/stdc++.h>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x),next(NULL) {}
};
ListNode* swapPairs(ListNode* A) {
    if(A==NULL || A->next==NULL) return A;
    ListNode* res = A->next;
    ListNode* curr=A;ListNode* head=A->next;ListNode* non;ListNode* prev;ListNode* n;
    prev=curr;
    ListNode* dum=prev->next->next;
    head->next=curr;
    while(dum!=NULL && dum->next)
    {
        non=dum->next; n=dum;
        dum=dum->next->next;
        prev->next=non;
        prev=prev->next;
        prev->next=n;prev=prev->next;   
    }

    prev->next=dum;
    return head;
}