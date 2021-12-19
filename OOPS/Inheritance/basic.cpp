#include <bits/stdc++.h>
using namespace std;

class Vehicle
{
public:
    int mileage;
    int maxSpeed;
    Vehicle(int x, int y)
    {
        mileage = x;
        maxSpeed = y;
    }
    void show()
    {
        cout << "Mileage is: " << mileage << endl;
        cout << "Maximum speed is: " << maxSpeed << endl;
    }
};

class Scooter : public Vehicle
{
public:
    int numOfWheels;
    Scooter(int x, int y, int z) : Vehicle(x, y)
    {
        mileage = x;
        maxSpeed = y;
        numOfWheels = z;
    }
};
int main()
{
    Vehicle obj(18, 120);
    obj.show();
    Scooter obj1(100, 120, 23);
    obj1.show();
    return 0;
}