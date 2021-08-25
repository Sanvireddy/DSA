#include <bits/stdc++.h>
using namespace std;

class engine
{
protected:
    string enginetype;
};

class car : public engine
{
public:
    void setEngine(string eng)
    {
        enginetype = eng;
    }
    void get()
    {
        cout << "Engine type is: " << enginetype << endl;
    }
};

int main()
{
    car obj;
    obj.setEngine("yesYamaha");
    obj.get();
    return 0;
}