#include <bits/stdc++.h>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x),next(NULL) {}
};
ListNode* solve(ListNode* A) {
    if(A==NULL || A->next==NULL || A->next->next==NULL) return A;
    vector<int> v;
    int i=0;ListNode* head=A;ListNode* res=A;
    while(A!=NULL)
    {
        i++;  
        if(i%2==0) v.push_back(A->val);
    A=A->next;
    }
    i=0;int n=v.size();
    reverse(v.begin(),v.end());
    while(head!=NULL)
    {
        i++;
        if(i%2==0) head->val=v[(i-1)/2];
        
        head=head->next;
    }
    return res;
}