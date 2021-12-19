#include <bits/stdc++.h>
using namespace std;

int sum(int x, int y, int w = 0)
{
    return (x + y + w);
}

int main()
{
    // default arguments are assigned from right to left
    int x = 20, y = 20, w = 23;
    cout << "After overwrinting: " << sum(x, y, w) << endl;
    x = 20;
    y = 20;
    cout << "Before overwriting: " << sum(x, y) << endl;
    return 0;
}
