#include <bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;
};

ListNode* removeNthFromEnd(ListNode* A, int B) {
    int len=0;
    ListNode* head = A;
    ListNode* ptr=A;
    while(ptr!=NULL)
    {
        ptr=ptr->next;
        len++;
    }
    if(B>=len)
    {
        A=A->next;
        return A;
    }
    if(B==0) B=1;
    while(len!=(B+1))
    {
        A=A->next;
        len--;
    }
    A->next=A->next->next;
    return head;
}