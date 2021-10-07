#include <iostream>
#include <stack>
using namespace std;

string PrefixToInfix(string prefix)
{
    stack<string> s;
    for (int i = (prefix.size() - 1); i >= 0; i--)
    {
        if ((prefix[i] >= 'a' && prefix[i] <= 'z') || (prefix[i] >= 'A' && prefix[i] <= 'Z'))
        {
            string op(1, prefix[i]);
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
            s.push("(" + temp1 + prefix[i] + temp2 + ")");
        }
    }
    return s.top();
}

int main()
{
    string infix, prefix;
    cout << "Enter a Prefix expression: " << endl;
    cin >> prefix;
    infix = PrefixToInfix(prefix);
    cout
        << "INFIX EXPRESSION: " << infix;
    cout << endl;
    return 0;
}