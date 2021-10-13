#include <iostream>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

string PostfixToInfix(string postfix)
{
    stack<string> s;
    for (int i = 0; i < postfix.size(); i++)
    {
        if ((postfix[i] >= 'a' && postfix[i] <= 'z') || (postfix[i] >= 'A' && postfix[i] <= 'Z'))
        {
            string op(1, postfix[i]);
            //this will make 1 copy of char in postfix[i]
            //it also changes the type from 'char' to 'string'
            s.push(op);
        }
        else
        {
            string temp1 = s.top();
            s.pop();
            string temp2 = s.top();
            s.pop();
            s.push('(' + temp2 + postfix[i] + temp1 + ')');
        }
    }
    return s.top();
}

int main()
{
    string infix, postfix;
    cout << "Enter a Postfix expression: " << endl;
    cin >> postfix;
    infix = PostfixToInfix(postfix);
    cout << "INFIX EXPRESSION: " << infix;
    cout << endl;
    string s="12";
    cout<<stoi(s)<<endl;
    return 0;
}