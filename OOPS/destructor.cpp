#include <bits/stdc++.h>
using namespace std;

class Geeks
{
public:
    int id;
    //destructor
    ~Geeks()
    {
        cout << "Default constructor is called for id: " << id << endl;
    }
};

int main()
{
    Geeks obj1;
    obj1.id = -1;
    int i = 0;
    while (i < 5)
    {
        Geeks obj2;
        obj2.id = i;
        i++;
    } //Scope for obj2 ends
    return 0;
    //scope for obj1 ends here
}