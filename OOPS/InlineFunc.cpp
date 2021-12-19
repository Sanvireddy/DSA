#include <bits/stdc++.h>
using namespace std;

inline int sum(int x, int y) { return x + y; }

class Arithmetic
{
public:
    int x;
    int y;
    inline int Sum() { return x + y; }
    int product();
};
inline int Arithmetic::product()
{
    return x * y;
}
int main()
{
    int p = 10, q = 10;
    cout << "Sum " << sum(p, q) << endl;
    Arithmetic obj;
    obj.x = 10;
    obj.y = 11;
    cout << "Sum using class " << obj.Sum() << endl;
    cout << "Product using class " << obj.product() << endl;
    return 0;
}