#include <iostream>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int data;
    Node(int key)
    {
        left = NULL;
        right = NULL;
        data = key;
    }
};

int searchFor(int arr[], int start, int end, int key)
{
    if (start > end)
        return -1;
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == key)
            return i;
    }
}

Node *buildTree(int pre[], int in[])
{
    int n = sizeof(pre) / sizeof(pre[0]);
    for (int i = 0; i < n; i++)
    {
        Node *root = new Node(pre[i]);
        int k = searchFor(in, i, n, pre[i]);
        }
}
