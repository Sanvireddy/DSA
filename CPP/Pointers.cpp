#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 9;
    int *b = &a;
    int *c=&a;
    cout<<"Before changing value of ptr ";
    cout<<"Unchanged ptr "<<b<<" & Changed ptr "<<c<<endl;
    b+=2;
    cout<<"AFter changing value of ptr ";
    cout<<"Unchanged ptr "<<b<<" & Changed ptr "<<c<<endl;
    cout<<"Unchanged ptr "<<(*b)<<" & Changed ptr "<<(*c)<<endl;
    
    // & --> Address of operator
    // * --> dereference of operator
    // every pointer has 2 bytes

    double db=12.3;
    double* ptr_db=&db;
    cout<<"INT "<<b<<" double "<<ptr_db<<endl;
    return 0;
}