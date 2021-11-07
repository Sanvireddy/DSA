#include <bits/stdc++.h>
using namespace std;

bool isValidBST(vector<int> v)
{
    stack<int> s;

    // for storing the parent of the element going to add
    int parent = -1;

    for (int i = 0; i < v.size(); i++)
    {
        // pop the elements from the stack if it is less than the element going to be inserted
        while (!s.empty() && s.top() < v[i])
        {
            // visualise this step as we are moving upwards
            // updating the parent because if the element is greater than top of stack
            // it can also be the right child of it's parent
            parent = s.top();
            s.pop();
        }
        if (parent < v[i])
            return 0;
        s.push(v[i]);
    }
    return 1;
}

int main()
{
    vector<int> v;
    v.push_back(40);
    v.push_back(30);
    v.push_back(35);
    v.push_back(20);
    v.push_back(80);
    v.push_back(100);
    cout << isValidBST(v) << endl;
    return 0;
}
