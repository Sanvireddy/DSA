#include <bits/stdc++.h>
using namespace std;

class square
{
public:
    double side;
    double area()
    {
        return side * side;
    }
};

int main()
{
    square obj;
    obj.side = 4.2;
    cout << obj.area() << endl;
    return 0;
}