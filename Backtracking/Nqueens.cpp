#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int **arr, int x, int y)
{
    int r = x - 1;
    int c = y;
    while (r >= 0)
    {
        if (arr[r][c])
            return false;
        r--;
    }
    r = x;
    c = y - 1;
    while (c >= 0)
    {
        if (arr[r][c])
            return false;
        c--;
    }
    r = x - 1;
    c = y - 1;
    while (r >= 0 && c >= 0)
    {
        if (arr[r][c])
            return false;
        r--;
        c--;
    }
    r = x - 1;
    c = y + 1;
    int n = sizeof(arr[0]) / sizeof(arr[0][0]);
    while (r >= 0 && c < n)
    {
        if (arr[r][c])
            return false;
        r--;
        c++;
    }

    return true;
}

bool Nqueens(int **arr, int n, int x, int **sol)
{
    if (x >= n)
    {
        return true;
    }

    for (int col = 0; col < n; col++)
    {
        //we are checking for every column
        //if it is safe
        //we try to place in next row, if it is safe we return true;
        //else we will backtrack it
        if (isSafe(arr, x, col))
        {
            sol[x][col] = 1;
            if (Nqueens(arr, n, x + 1, sol))
            {
                return true;
            }
            sol[x][col] = 0;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
            arr[i][j] = 0;
    }

    int **sol = new int *[n];
    for (int i = 0; i < n; i++)
    {
        sol[i] = new int[n];
        for (int j = 0; j < n; j++)
            sol[i][j] = 0;
    }

    if (Nqueens(arr, n, 0, sol))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
    }

    /*
    vector<int> v = {1, 2, 3, 4};
    swap(v[1], v[2]);
    cout << v[1] << " " << v[2] << endl;
    */
    return 0;
}
