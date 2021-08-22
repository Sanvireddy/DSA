#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, str;
    cin >> s;
    int arr[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        arr[s[i] - 97]++;
    }
    int t = 0;
    while (t != 26)
    {
        t = 0;
        for (int i = 0; i < 26; i++)
        {
            if (arr[i] != 0)
            {
                //cout << (char)(i + 97);
                str += (char)(i + 97);
                arr[i]--;
            }
        }
        for (int i = 25; i >= 0; i--)
        {
            if (arr[i] != 0)
            {
                //cout << (char)(i + 97);
                str += (char)(i + 97);
                arr[i]--;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (arr[i] == 0)

                t++;
        }
    }
    cout << str << endl;
    /*for (int i = 0; i < 26; i++)
        cout << arr[i] << " ";
    cout << endl;
*/
    return 0;
}