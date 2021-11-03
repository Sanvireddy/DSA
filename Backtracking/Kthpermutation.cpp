#include <bits/stdc++.h>
using namespace std;
#define p = 3

void permutation(int start,int end,vector<string> v,int cnt)
{
    
    if(cnt==0) 
    {
        for(int i=0;i<=2;i++){ cout<<v[i]<<" ";}cout<<endl;
    }
    if(start>end) return;
    for(int i=start;i<=end;i++)
    {
            swap(v[i],v[start]);
            cnt--;
            permutation(start+1,end,v,cnt);
            swap(v[i],v[start]);
    }
    return;
}

int main()
{
    vector<string> v;
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        v.push_back(to_string(i));
    }
    permutation(0,n-1,v,k-1);
    for(int i=0;i<n;i++) cout<<v[i]<<" ";
    cout<<char((60%26)+'A')<<6<<endl;
    return 0;
}