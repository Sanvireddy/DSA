#include <bits/stdc++.h>
using namespace std;

class Geeks
{
public:
    int id;
    //Default constructor
    Geeks()
    {
        cout << "Default constructor is called" << endl;
        id = -1;
    }

    //Parameterized constructor
    Geeks(int x)
    {
        cout << "Parameterized constructor is called" << endl;
        id = x;
    }
};

int main()
{
    Geeks obj1;
    Geeks obj2(8);
    cout << obj1.id << endl;
    cout << obj2.id << endl;
    return 0;
}