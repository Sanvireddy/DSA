#include <bits/stdc++.h>
using namespace std;


int oddsum(int n)
{
    if(n==1 || n==2) return 1;
    n-=2;
    long long int res=1 + n*(n+1);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<oddsum(n)<<endl;
    }
    return 0;
}