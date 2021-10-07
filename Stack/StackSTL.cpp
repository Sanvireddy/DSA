#include <iostream>
#include <stack>
using namespace std;

int main()
{
    //given a stack of integers: 1,8,3,6,2
    //find sum of all integers
    stack<int> s1;
    stack<int> s2;
    //we can only swap elements of stacks iff they are of same type
    //but size may vary
    int sum = 0;
    s1.push(1);
    s1.push(8);
    s1.push(3);
    s1.push(6);
    s1.push(2);

    s2.push(1);
    s2.push(3);
    s2.push(3);
    s2.push(5);
    s2.push(7);

    //To find sum of elements
    while (!s1.empty())
    {
        sum += s1.top();
        s1.pop();
    }
    cout << "Sum is: " << sum << ", Size of stack is: " << s1.size() << endl;

    s1.push(1);
    s1.push(8);
    s1.push(3);
    s1.push(6);
    s1.push(2);

    s1.swap(s2);
    //print elements of stack one
    while (!s1.empty())
    {
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << endl;

    while (!s2.empty())
    {
        cout << s2.top() << " ";
        s2.pop();
    }
    cout << endl;
    return 0;
}