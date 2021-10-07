#include <bits/stdc++.h>
using namespace std;
class datamem
{
public:
    void getprod(int k1, int k2)
    {
        cout << "Total product is: " << k1 * k2 << endl;
    }
};
class product
{
private:
    int data1;
    int data2;

public:
    int getdat1(int d1)
    {
        data1 = d1;
        return data1;
    }
    int getdat2(int d2)
    {
        data2 = d2;
        return data2;
    }
    friend void datamem::getprod(int getdata1, int getdata2);
};

int main()
{
    product obj1;
    datamem obj2;

    obj2.getprod(obj1.getdat1(2), obj1.getdat2(5));
    return 0;
}