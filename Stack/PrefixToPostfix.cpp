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

string PrefixToPostfix(string prefix)
{
    stack<string> s;
    for (int i = (prefix.size() - 1); i >= 0; i--)
    {
        if (!isOperator(prefix[i]))
        {
            string op(1, prefix[i]);
            s.push(op);
        }
        else
        {
            string temp1 = s.top();
            s.pop();
            string temp2 = s.top();
            s.pop();
            s.push(temp1 + temp2 + prefix[i]);
        }
    }
    string k = s.top();
    //reverse(k.begin(), k.end());
    return k;
}

int main()
{
    string prefix, postfix;
    cout << "Enter a Prefix expression: " << endl;
    cin >> prefix;
    postfix = PrefixToPostfix(prefix);
    cout
        << "POSTFIX EXPRESSION: " << postfix;
    cout << endl;
    return 0;
}
