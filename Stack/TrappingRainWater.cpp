#include <vector>
#include <iostream>
using namespace std;


int trap(const vector<int> &A) {
    int n=A.size();
    vector<int> left(n,0);
    vector<int> right(n,0);
    left[0]=-1;right[n-1]=-1;
    for(int i=1;i<n;i++)
        left[i]=max(left[i-1],A[i-1]);
    for(int i=n-2;i>=0;i--)
    right[i]=max(right[i+1],A[i+1]);
    int res=0;
    for(int i=0;i<n;i++)
    {
        if(min(left[i],right[i])>A[i]) res+=(-A[i]+min(right[i],left[i]));
    }
    return res;
}
int main()
{
    vector<int> vect;
    vect.push_back(8);
    vect.push_back(8);
    vect.push_back(8);
    cout<<trap(vect)<<endl;
    return 0;
}