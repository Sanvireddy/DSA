#include <bits/stdc++.h>
using namespace std;

class square
{
    // Access specifier
    public:

    // Data member
    double side;


    // Member functions
    // it is not defined inside the class.
    void printSide();
    
    double area()
    {
        return side * side;
    }
};
 // To define a member function outside the class
 // we have to use scope resolution operator :: along with class & func name
void square::printSide()
{
    cout<<"Value of side is "<<side<<endl;
}
int main()
{
    square obj;
    obj.side = 4.2;
    cout << obj.area() << endl;
    obj.printSide();
    return 0;
}