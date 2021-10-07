#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v[2];
    v[0].push_back(10);
    v[0].push_back(19);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}