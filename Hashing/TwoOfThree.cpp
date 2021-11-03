#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    map<int,int> m1;
    map<int,int> m2;
    map<int,int> m3; map<int,int> m;
    vector<int> v;
    for(int i=0;i<A.size();i++) m1[A[i]]++;
    for(int i=0;i<B.size();i++) m2[B[i]]++;
    for(int i=0;i<C.size();i++) m3[C[i]]++;
    for(int i=0;i<A.size();i++)
    {
        if(m2.find(A[i])!=m2.end() || m3.find(A[i])!=m3.end()) m[A[i]]++;
    }
    for(int i=0;i<B.size();i++)
    {
        if(m1.find(B[i])!=m1.end() || m3.find(B[i])!=m3.end()) m[B[i]]++;
    }
    for(int i=0;i<C.size();i++)
    {
        if(m2.find(C[i])!=m2.end() || m1.find(C[i])!=m1.end()) m[C[i]]++;
    }
    for(auto it=m.begin();it!=m.end();it++)
    {
        v.push_back(it->first);
    }
    return v;
}

int main()
{
    vector<int> v;
    v.push_back(9);
    v.push_back(0);
    v.push_back(9);
    v.push_back(2);
    v.push_back(3);
    vector<int> v1;
    v1.push_back(9);
    v1.push_back(0);
    v1.push_back(9);
    v1.push_back(2);
    v1.push_back(3);vector<int> v3;
    v3.push_back(9);
    v3.push_back(0);
    v3.push_back(9);
    v3.push_back(9);
    v3.push_back(2);
    v3.push_back(3);
    vector<int> res;
    res=solve(v,v1,v3);
    return 0;
}