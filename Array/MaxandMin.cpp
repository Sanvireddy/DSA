#include <bits/stdc++.h>
using namespace std;

pair<int,int> MinMax(vector<int> arr)
{
    pair<int,int> p;
    p.first = arr[0];
    p.second=arr[0];
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i] < p.first)
        p.first = arr[i];
        else 
        p.second = max(arr[i],p.second);
    }
    return p;
}

int main(){
    vector<int> arr = {2,5,912,4,2,-1,7,8,99};
    pair<int,int> p;
    p=MinMax(arr);
    cout << p.first << " " << p.second << endl;
    return 0;
}