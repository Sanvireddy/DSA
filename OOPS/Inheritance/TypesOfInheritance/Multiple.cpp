#include<bits/stdc++.h>
using namespace std;
class SuperClass1{
    public:
    SuperClass1()
    {
        cout<<"This is super class - 1"<<endl;
    }
};

class SuperClass2{
    public:
    SuperClass2()
    {
        cout<<"This is super class - 2"<<endl;
    }
};

// sub class derived from a 2 base classes
class Subclass : public SuperClass1,SuperClass2{

};
int main()
{
     //creating object of sub class will
    //invoke the constructor of base classes
    Subclass obj;
    return 0;
}