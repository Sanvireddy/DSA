#include <bits/stdc++.h>
using namespace std;



int usingSet(int arr[],int n,int k)
{
    //TC: O(logn)
    //SC: O(n)
    set<int> s(arr,arr+n);
    set<int>::iterator it=s.begin();
    advance(it,k-1);
    return *it;

}


int main()
{
    int arr[] = {12,3,4,5,7,19};
    int k=4;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<< usingSet(arr,n,k);
    return 0;
}