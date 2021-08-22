#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[5] = {1, 8, 3, 2};
    cout << "First element is " << *a << endl;
    cout << "Second element is " << *(a + 1) << endl;
    cout << "First element is " << a[0] << endl;

    int b[2][3] = {{10, 2, 3}, {1, 42, 15}};
    cout << "First element is " << **b << endl;

    //this prints b + sizeof 1D array of 3 elements
    cout << "First element is " << *(*(b + 1)) << endl;

    //*(b+1) points to second b[1] and +2 indicates second element of second row
    cout << "b[1][2] is " << *(*(b + 1) + 2) << endl;
    cout << "b[1][2] is " << *(b[1] + 2) << endl;
    cout << "Second element is " << *(*b + 1) << endl;
    cout << "Second element is " << *(*b + 4) << endl;
    return 0;
}