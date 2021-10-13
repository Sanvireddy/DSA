#include <bits/stdc++.h>
using namespace std;

int evalRPN(vector<string> &A) {
    stack<int> s;
    int res;
    for(int i=0;i<A.size();i++)
    {
        if(!(A[i]=="+" || A[i]=="-" || A[i]=="*" || A[i]=="/"))
        { int k = stoi(A[i]);s.push(k);}
        else{
            int temp1=s.top();s.pop();
            int temp2=s.top();s.pop();
            if(A[i]=="+")
            s.push(temp1+temp2);
            else if(A[i]=="-") s.push(temp2-temp1);
            else if(A[i]=="/") s.push(temp2/temp1);
            else s.push(temp1*temp2);
        }
        
    }
    return s.top();
}

int main()
{
    vector<string> v;
    v.push_back("12");
    v.push_back("1");
    v.push_back("+");
    v.push_back("2");
    v.push_back("-");
    cout<<evalRPN(v)<<endl;
    return 0;
}
