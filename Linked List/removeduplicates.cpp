#include <bits/stdc++.h>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x),next(NULL) {}
};

void insert(ListNode** root, int item)
{
    ListNode* temp = new ListNode(item);
    ListNode* ptr;
 
    if (*root == NULL)
        *root = temp;
    else {
        ptr = *root;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}
 
ListNode* deleteDuplicates(ListNode* A) {
    if(A==NULL || A->next==NULL) return A;
    ListNode* result=NULL;
    while(A!=NULL)
    {
    bool b=0;
    while((A!=NULL) && (A->next!=NULL) && (A->val==A->next->val)) {b=1;A=A->next;}
    if(b) A=A->next;
    else {insert(&result,A->val);A=A->next;}
    }
    return result;
}

ListNode* DeleteDuplicates(ListNode* A) {
    if(A==NULL || A->next==NULL) return A;
    ListNode* prev=A;
    ListNode* head = A;
    while(A && A->next)
    {
        bool b=0;
        if(A && A->next &&  (A->val)==(A->next->val)) prev=A;
        while(A && A->next &&  (A->val)==(A->next->val))
        {
            A=A->next;
        }
        if(prev->val==A->val){
            A=A->next;
        }
        prev->next = A;
        prev=A;
    }    
    return head;
}