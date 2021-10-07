#include <bits/stdc++.h>
using namespace std;

class sum
{
private:
    int data1;
    int data2;

public:
    void getdat1(int dat1)
    {
        data1 = dat1;
    }
    void getdat2(int dat2)
    {
        data2 = dat2;
    }
    friend class datamem;
};

class datamem
{
private:
    int totalsum;

public:
    void totsum(sum &s)
    {
        totalsum = s.data1 + s.data2;
        cout << "Total sum is " << totalsum << endl;
    }
};

int main()
{
    sum obj1;
    datamem obj2;
    obj1.getdat1(5);
    obj1.getdat2(9);
    obj2.totsum(obj1);
    return 0;
}