#include <bits/stdc++.h>
using namespace std;
#define MAX_LEN 100

void strsort(char arr[][MAX_LEN], int n)
{
    int min, k;
    for (int i = 0; i < n; i++)
    {
        min = i;

        for (int j = i + 1; j < n; j++)
        {
            k = 0;
            /*
            while ((k < arr[j].length()) && (k < arr[min].length()))
            {
                if ((int)arr[j][k] < (int)arr[min][k])
                {
                    min = j;

                    break;
                }
                else if ((int)arr[j][k] == (int)arr[min][k])
                    k++;
                else
                    break;
            }
            */
            if (strcmp(arr[min], arr[j]) > 0)
                min = j;
        }

        swap(arr[i], arr[min]);
    }
    return;
}

void printarray(char arr[][MAX_LEN], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()

{
    char arr[][MAX_LEN] = {"style", "hehe", "kullu", "flower", "floppy", "apple"};

    int n = sizeof(arr) / sizeof(arr[0]);
    //cout << n << endl;
    //cout << (int)arr[0][0] << endl;
    //cout << arr[0].length() << endl;
    printarray(arr, n);
    strsort(arr, n);

    printarray(arr, n);

    return 0;
}