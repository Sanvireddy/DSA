#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    else
        return false;
}

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string InfrixToPostfix(stack<char> s, string infix)
{
    string Postfix;
    for (int i = 0; i < infix.size(); i++)
    {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
            Postfix += infix[i];
        else if (infix[i] == '(')
            s.push(infix[i]);
        else if (infix[i] == ')')
        {
            while ((!s.empty()) && (s.top() != '('))
            {
                char temp = s.top();
                Postfix += temp;
                s.pop();
            }
            if (s.top() == '(')
            {
                s.pop();
            }
        }
        else if (isOperator(infix[i]))
        {
            if (s.empty())
                s.push(infix[i]);
            else
            {
                if (precedence(infix[i]) > precedence(s.top()))
                    s.push(infix[i]);
                else if (precedence(infix[i]) == precedence(s.top()) && infix[i] == '^')
                    s.push(infix[i]);
                else
                {
                    while ((!s.empty()) && (precedence(infix[i]) <= precedence(s.top())))
                    {
                        Postfix += s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }
    while (!s.empty())
    {
        Postfix += s.top();
        s.pop();
    }
    return Postfix;
}

int main()
{
    string infix, postfix;
    cout << "Enter a Infix expression: " << endl;
    cin >> infix;
    stack<char> s;
    postfix = InfrixToPostfix(s, infix);
    cout
        << "POSTFIX EXPRESSION: " << postfix;
    cout << endl;
    return 0;
}