#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>
using namespace std;

struct struct_ex
{
    int integer;
    string name;
    char character;
};

union union_ex
{
    int integer;
    string name;
    char character;
};

int main()
{
    struct_ex s = {2,"geeksforgeeks",'s'};
    union_ex u = {3,"geekuforgeeku",'u'}; 
    cout<<s.integer<<" "<<s.character<<" "<<s.name<<endl;
    cout<<u.integer<<" "<<u.character<<" "<<u.name<<endl;
    return 0;
}
