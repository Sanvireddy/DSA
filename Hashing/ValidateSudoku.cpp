#include <bits/stdc++.h>
using namespace std;

int isValidSudoku(const vector<string> &A) {
    for(int i=0;i<9;i++)
    {
        map<char,int> m;
        for(int j=0;j<9;j++)
        {
            m[A[i][j]]++;
            if(m[A[i][j]]>=2 && A[i][j]!='.') return 0;
        }
        map<char,int> mp;
        for(int j=0;j<9;j++)
        {
            mp[A[j][i]]++;
            if(mp[A[j][i]]>=2 && A[j][i]!='.') return 0;
        }
    }
    int g=0,h=0;
    while(g<9 && h<9)
    {
        map<char,int> m1;
        for(int i=g;i<g+3;i++)
        {
            for(int j=h;j<h+3;j++)
            {
                 m1[A[i][j]]++;
            if(m1[A[i][j]]>=2 && A[i][j]!='.') return 0;
            }
        }
        map<char,int> m2;g+=3;
        for(int i=g;i<g+3;i++)
        {
            for(int j=h;j<h+3;j++)
            {
                 m2[A[i][j]]++;
            if(m2[A[i][j]]>=2 && A[i][j]!='.') return 0;
            }
        }
        map<char,int> m3;g+=3;
        for(int i=g;i<g+3;i++)
        {
            for(int j=h;j<h+3;j++)
            {
                 m3[A[i][j]]++;
            if(m3[A[i][j]]>=2 && A[i][j]!='.') return 0;
            }
        }
        h+=3;g=0;
    }
    return 1;
}

int main()
{
    vector<string> v;
    v.push_back("53..7....");
    v.push_back("6..195...");
    v.push_back(".98....6.");
    v.push_back("8...6...3");
    v.push_back("4..8.3..1");
    v.push_back("7...2...6");
    v.push_back(".6....28.");
    v.push_back("...419..5");
    v.push_back("....8..79");
    cout<< isValidSudoku(v) << endl;
    return 0;
}