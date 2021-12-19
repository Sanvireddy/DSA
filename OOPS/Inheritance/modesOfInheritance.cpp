#include<bits/stdc++.h>
using namespace std;

class A
{
    public:
        int x=1;

        protected:
        int y=2;
        private:
        int z=3;
    public:
    void show()
    {
        cout<<y<<endl;
    }
    
};

class B: public A{
    void show(A &a)
    {
        cout<<"x is public "<<a.x<<endl;
        cout<<"y is protected ";
         a.show();
         cout<<endl;
        cout<<"x is private (inaccessible) "<<endl;
    }
};
int main()
{
    A obj;

    return 0;
}
