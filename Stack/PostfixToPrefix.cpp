#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    else
        return false;
}

string PostfixToPrefix(string postfix)
{
    stack<string> s;
    for (int i = 0; i < postfix.size(); i++)
    {
        if (!isOperator(postfix[i]))
        {
            string op(1, postfix[i]);
            s.push(op);
        }
        else
        {
            string temp1 = s.top();
            s.pop();
            string temp2 = s.top();
            s.pop();
            s.push(postfix[i] + temp2 + temp1);
        }
    }
    return s.top();
}

int main()
{
    string prefix, postfix;
    cout << "Enter a Postfix expression: " << endl;
    cin >> postfix;
    prefix = PostfixToPrefix(postfix);
    cout
        << "PREFIX EXPRESSION: " << prefix;
    cout << endl;
    return 0;
}
