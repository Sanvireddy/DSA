#include <bits/stdc++.h>
using namespace std;

class Stack
{
    int top;
    int size;
    int *arr;

public:
    Stack(int cap)
    {
        size = cap;
        arr = new int[size];
        top = -1;
    }
    void push(int ele)
    {
        if (top == size)
            cout << "Stack overflow" << endl;
        else
        {
            top++;
            arr[top] = ele;
        }
    }
    int peek()
    {
        if (top == -1)
            cout << "Stack is empty" << endl;
        return arr[top];
    }
    bool isEmpty()
    {
        if (top == -1)
            return 1;
        return 0;
    }
    void pop()
    {
        if (isEmpty())
            cout << "Stack is empty" << endl;
        else
            top--;
    }
    void print()
    {
        if (isEmpty())
            cout << "Stack is empty" << endl;
        else
        {
            while (top != -1)
            {
                cout << arr[top] << " ";
                top--;
            }
            cout << endl;
        }
    }
};
int main()
{
    Stack s(9);
    s.push(9);
    s.push(8);
    s.push(7);
    s.push(6);
    s.push(5);
    s.pop();
    cout << s.peek() << endl;
    s.pop();
    cout << s.peek() << endl;
    s.print();
    return 0;
}