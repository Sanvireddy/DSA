#include <bits/stdc++.h>
using namespace std;

class Parent
{
public:
    virtual string print()
    {
        return "This is parent area";
    }
};

class Child1 : public Parent
{
private:
    string myname;

public:
    Child1(const string &name)
    {
        myname = name;
    }
    string print()
    {
        return "This is " + myname + " class";
    }
};

int main()
{
    Parent *p = new Parent();
    cout << p->print() << endl;
    Child1 *c = new Child1("Sanvi");
    cout << c->print() << endl;
    Parent *p2 = c;
    cout << p2->print() << endl;

    return 0;
}