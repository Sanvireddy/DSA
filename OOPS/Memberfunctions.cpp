#include <bits/stdc++.h>
using namespace std;

class Hospital
{
private:
    string name;
    int regnum;

public:
    void printname(string s)
    {
        //defined inside class definition
        name = s;
        cout << "Name of the hospital is: " << name << endl;
    }

    //defined outside class definition
    void printreg(int reg);
};

void Hospital ::printreg(int reg)
{
    regnum = reg;
    cout << "Reg num of " << name << " is: " << regnum << endl;
}

int main()
{
    Hospital obj;
    //obj.name = "Sai krupa";
    obj.printreg(434343);
    obj.printname("Leelavathi Hospital");
    obj.printreg(12345);
    return 0;
}

//even if we define the data variables privately
// we can obtain them using getters and setters