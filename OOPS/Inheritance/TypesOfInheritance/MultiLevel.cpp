#include<bits/stdc++.h>
using namespace std;
class Vehicle{
    public:
    Vehicle()
    {
        cout<<"This is a vehicle"<<endl;
    }
};
// first sub_class derived from class vehicle
class FourWheeler : public Vehicle{
    public:
    FourWheeler()
    {
        cout<<"Objects with 2 wheels are vehicles"<<endl;
    }
};

// sub class derived from the derived base class fourWheeler
class Auto: public FourWheeler{
    public:
    Auto()
    {
        cout<<"Auto is a vehicle with 4 wheels."<<endl;
    }
};
int main()
{
    //creating object of sub class will
    //invoke the constructor of base classes
    Auto obj;
    return 0;
}