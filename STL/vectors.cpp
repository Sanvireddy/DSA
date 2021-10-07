#include <bits/stdc++.h>
using namespace std;

bool comp(int x, int y) { return x > y; }
int main()
{
    vector<int> A = {11, 2, 3, 1, 4};
    sort(A.begin(), A.end()); //O(nlogn)

    //whether an element is present or not in vector
    //O(logn)  (binary search)
    bool present = binary_search(A.begin(), A.end(), 4);
    cout << present << endl;
    present = binary_search(A.begin(), A.end(), 3);
    cout << present << endl;

    A.push_back(10);
    A.push_back(10);
    A.push_back(10);
    A.push_back(10);
    A.push_back(10);
    A.push_back(11);
    sort(A.begin(), A.end());
    vector<int> B = {0, 4, 5};
    //how to find out the first occurence
    //after arraay is sorted
    vector<int>::iterator it = lower_bound(A.begin(), A.end(), 11); //>=
    vector<int>::iterator it3 = lower_bound(B.begin(), B.end(), 0); //>=
    if ((it3) == B.begin())
        cout << *(it3) << endl;
    //last occurrence
    //first element that is strictly greater
    vector<int>::iterator it2 = upper_bound(A.begin(), A.end(), 11); // >
    //bounds are done in O(logn)
    cout << *it << " " << *it2 << endl;

    //to know num of occurences
    cout << it2 - it << endl; //O(1)

    //sort vector in decreasing order
    sort(A.begin(), A.end(), comp);
    for (auto x : A)
    {
        x++;
        cout << x << " ";
    }
    cout << endl;

    //pass by reference
    for (auto &x : A)
    {
        x++;
        cout << x << " ";
    }
    cout << endl;
}