#include <iostream>
using namespace std;

int binarysearch(int arr[], int l, int r, int key)
{
    if (l > r)
        return -1;
    int mid = (l + r) / 2;
    if (l == r)
        return l;
    if (arr[mid] == key)
        return mid;
    if (key > arr[r] || key < arr[l])
        return -1;
    if (key < arr[mid] && key >= arr[l])
        return binarysearch(arr, l, mid - 1, key);
    if (key > arr[mid] && key <= arr[r])
        return binarysearch(arr, mid + 1, r, key);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << binarysearch(arr, 0, n - 1, 8) << endl;
    return 0;
}