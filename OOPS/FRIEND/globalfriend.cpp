#include <bits/stdc++.h>
using namespace std;

class substract
{
    int a;
    int b;

public:
    int geta(int a)
    {
        a = a;
        return a;
    }
    int getb(int b)
    {
        b = b;
        return b;
    }
    friend void sub(int geta, int getb);
};

void sub(int k1, int k2)
{
    cout << "Subtracting second from first gives: " << k1 - k2 << endl;
}

int main()
{
    substract obj1;
    sub(obj1.geta(9), obj1.getb(8));
    return 0;
}