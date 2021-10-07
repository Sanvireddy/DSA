#include <bits/stdc++.h>
using namespace std;

vector<int> summing(vector<int> a, vector<int> b)
{
    int summ = 0, k;
    for (int i = 0; i < (min(a.size(), b.size())); i++)
    {
        k = (a[i] + b[i] + summ) / 10;
        a[i] = (a[i] + b[i] + summ) % 10;
        summ = k;
    }
    if (a.size() > b.size())
    {
        int i = b.size();
        while (i != a.size())
        {
            k = (a[i] + summ) / 10;
            a[i] = (a[i] + summ) % 10;
            summ = k;
            i++;
        }
        if (summ)
            a.push_back(summ);
    }
    else if (a.size() < b.size())
    {
        int i = a.size();
        while (i != b.size())
        {
            k = (b[i] + summ) / 10;
            a.push_back((b[i] + summ) % 10);
            summ = k;
            i++;
        }
        if (summ)
            a.push_back(summ);
    }

    return a;
}

string multiply(string A, string B)
{
    int s = 0;
    vector<int> k2;
    string fin;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        vector<int> k1;
        int p = 0;
        while (p != (A.size() - 1 - i))
        {
            k1.push_back(0);
            p++;
        }
        for (int j = B.size() - 1; j >= 0; j--)
        {
            k1.push_back(((A[i] - '0') * (B[j] - '0') + s) % 10);
            s = ((A[i] - '0') * (B[j] - '0') + s) / 10;
        }
        k1.push_back(s);
        k2 = summing(k2, k1);
    }
    for (int j = (k2.size() - 1); j >= 0; j--)
    {

        fin += to_string(k2[j]);
    }
    fin.erase(0, min(fin.find_first_not_of('0'), fin.size() - 1));
    return fin;
}

int main()
{
    string s1 = "9999", s2 = "9999";
    cout << multiply(s1, s2) << endl;
    return 0;
}