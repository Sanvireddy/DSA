#include <iostream>
#include <iterator>
#include <set>

using namespace std;

int main() {
    set<int> s;
    s.insert(900);
    s.insert(20);
    s.insert(20);
    s.insert(60);
    s.insert(40);
    s.insert(50);
    //prints in ascending order
    //whatever order you wanted to insert it should be done while
    //intializing the set not in iterator
    //changing in iterator does nothing
    set<int>::iterator it;
    for(it=s.begin();it!=s.end();it++)
    cout << *it << " ";
    cout << endl;

set<int,greater<int>> s1;
    s1.insert(900);
    s1.insert(20);
    s1.insert(20);
    s1.insert(60);
    s1.insert(40);
    s1.insert(50);
    //in descending order
    set<int>::iterator it1;
    for(it1=s1.begin();it1!=s1.end();it1++)
    cout << *it1 << " ";
    cout << endl;
    return 0;
}