#include<bits/stdc++.h>
using namespace std;
class SuperClass{
    public:
    SuperClass()
    {
        cout<<"This is super class"<<endl;
    }
};

// sub class derived from a single base classes
class Subclass : public SuperClass{

};
int main()
{
    //creating object of sub class will
    //invoke the constructor of base classes
    SuperClass obj;
    return 0;
}
