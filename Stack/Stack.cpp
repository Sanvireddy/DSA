#include <bits/stdc++.h>
using namespace std;

class Stack
{
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size)
    {
        arr = new int[size];
        top = -1;
        capacity = size;
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            //cout << "Stack is EMPTY\n";
            return true;
        }
        else
        {
            //cout << "Stack is not empty\n";
            return false;
        }
    }
    bool isFull()
    {
        if (top == (capacity - 1))
        {
            //cout << "Stack is FULL\n";
            return true;
        }
        else
        {
            //cout << "Stack is not full\n";
            return false;
        }
    }
    int peek(int i)
    {
        if (i > top)
        {
            cout << "Enter correct index\n";
            return INT_MAX;
        }
        cout << i << "th element is: ";
        return arr[i];
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!\n";
            return INT_MAX;
        }
        int a = arr[top];
        top--;
        cout << "Top element of the stack is: ";
        return a;
    }

    void push(int key)
    {
        if (isFull())
        {
            cout << "Stack overflow\n";
            return;
        }
        top++;
        arr[top] = key;
        return;
    }

    void printarray()
    {
        if (isEmpty())
            return;
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack s1(5);
    cout << s1.isEmpty() << endl;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(6);
    s1.printarray();
    cout << s1.peek(2) << endl;
    cout << s1.isFull() << endl;
    cout << s1.pop() << endl;
    cout << s1.isFull() << endl;
    return 0;
}