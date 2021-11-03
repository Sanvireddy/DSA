#include <bits/stdc++.h>
using namespace std;

class square
{
private:
    double side;

public:
    double area(double s)
    {
        double side = s;
        double Area = side * side;
        cout << "Side of a square is: " << side << endl;
        cout << "Area of a square is: ";
        return Area;
    }
};

int main()
{
    square obj;
    // private members are inaccessible outside the class
    // cout << obj.side() << endl;
    cout << obj.area(4.2) << endl;
    return 0;
}