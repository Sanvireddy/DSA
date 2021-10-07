#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    unordered_set<int> s;
    s.insert(5);
    s.insert(15);
    if (s.find(5) == s.end())
        cout << "Element not found!" << endl;
    else
        cout << "Elemet is found" << endl;
    cout << "No.of elements in s are " << s.size() << endl;
    cout << s.count(10) << endl;
    if (s.count(0) == 0)
        cout << "element not present" << endl;
    s.erase(10);
    s.erase(s.begin(), s.end());
    return 0;
}