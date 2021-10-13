#include <bits/stdc++.h>
using namespace std;

class StackNode
{
public:
    int val;
    StackNode *head;
    StackNode *next;
    StackNode *newNode(int data)
    {
        StackNode *stacknode = new StackNode();
        stacknode->val = data;
        stacknode->next = NULL;
        return stacknode;
    }
    void push(int val)
    {
        StackNode *node = newNode(val);
        node->next=head;
        head=node;
    }
    bool isEmpty()
    {
        if(head==NULL) return true;
        return false;
    }
    int peek()
    {
        if(isEmpty()) return INT_MIN;
        return head->val;
    }
    void pop()
    {
        if(isEmpty()) cout<<"Stack is empty"<<endl;
        head=head->next;
    }
};

int main()
{
    StackNode s;
    s.push(9);
    s.push(8);
    s.push(7);
    s.push(6);
    s.push(5);
    s.pop();
    cout << s.peek() << endl;
    s.pop();
    cout << s.peek() << endl;
    
    return 0;
}