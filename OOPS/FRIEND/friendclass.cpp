#include <bits/stdc++.h>
using namespace std;

class datamem
{
private:
    int data1;
    int data2;

public:
    datamem(int x, int y)
    {
        data1 = x;
        data2 = y;
    }
    friend class sum;
};

class subtract : public datamem
{
private:
    int d1;
    int d2;
    
};
class sum
{
private:
    int totalsum;

public:
    void totsum(datamem &s)
    {
        totalsum = s.data1 + s.data2;
        cout << "Total sum is " << totalsum << endl;
    }
    // s.d1 is inaccessible because friend function of base class
    // is not friend func of derived class

    /*
    void totsub(subtract &s)
    {
        cout << s.d1 - s.d2 << endl;
    }
    */
};

int main()
{
    datamem obj1(9, 10); // base class
    sum obj2;            // friend class of base class
    subtract obj3();     // derived class of base class

    // friend class can access private mem of base class since it is frnd of base
    obj2.totsum(obj1);

    return 0;
}