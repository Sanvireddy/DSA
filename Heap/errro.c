#include<stdio.h>
int f1( int );
void main()
{
    int a=10,b=20;
    char x=1,y=0;
    if(a,b,x,y)
    {
        printf("EXAM");
    }
}
int f1(int b)
{
    static int n=5;
    n++;

    return n;
}