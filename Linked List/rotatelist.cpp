#include <bits/stdc++.h>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x),next(NULL) {}
};

int getlength(ListNode* head)
{
    int i=0;
    while(head!=NULL)
    {
        head=head->next;
        i++;
    }
    return i;
}
ListNode* rotateRight(ListNode* A, int B) {
    if(B==0) return A;
    if(A==NULL && A->next==NULL) return A;
    
    int i=1;
    ListNode* curr=A;ListNode* head=A;ListNode* initial=A;
    int tot=getlength(curr);B%=tot;
    if(B==0) return A;
    tot-=B;
    while(i<tot)
    {
        initial=initial->next;
        i++;   
    }
    ListNode* Next=initial->next;
    ListNode* res=Next;
    initial->next=NULL;
    while(Next->next!=NULL)
    {
        Next=Next->next;
    }
    Next->next=head;
    return res;
}
