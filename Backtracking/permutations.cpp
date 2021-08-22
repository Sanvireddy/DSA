#include <iostream>
using namespace std;

void permutations(string s, int left, int right)
{
    if (left == right)
        cout << s << " ";
    for (int i = left; i <= right; i++)
    {
        //do
        swap(s[left], s[i]);

        //recur
        permutations(s, left + 1, right);

        //undo
        swap(s[left], s[i]);
    }
}

int main()
{
    string s = "abac";
    int n = s.size();

    //cout << s << endl;
    permutations(s, 0, n - 1);
    return 0;
}