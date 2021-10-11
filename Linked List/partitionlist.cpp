#include <bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;
};
ListNode* partition(ListNode* A, int B) {
    vector<int> v1;vector<int> v2;
    ListNode* node = A;
    ListNode* fin=A;
    while(node!=NULL)
    {
        if(node->val<B) v1.push_back(node->val);
        else v2.push_back(node->val);
        node=node->next;
    }
    int n1=v1.size(),n2=v2.size();
    //cout << n1 << " " << n2 << endl;
    int i=0,j=0;
    while(i<n1)
    {
        fin->val=v1[i];
        i++;fin=fin->next;
    }
    while(j<n2)
    {
        fin->val=v2[j];j++;fin=fin->next;
    }
    return A;
}


int main()
{
    return 0;
}