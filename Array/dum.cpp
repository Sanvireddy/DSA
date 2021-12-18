#include<bits/stdc++.h>
using namespace std;

int main()
{
    int A;
    cin>>A;
    int sign=1,rem,B=0;
    A*=sign;
    while(A>0)
    {
        rem=A%10;
        B=B*10+rem;
        A/=10;
    }
    if(B>INT_MAX) cout<<0<<endl;
    else cout<<B*sign<<endl;
}