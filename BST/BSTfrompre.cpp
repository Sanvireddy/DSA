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

Node *insert(Node *root, int key)
{
    if (root == NULL)
    {
        Node *root = new Node(key);
        return root;
    }
    if (root->data > key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

Node *pretoin(int arr[], int n)
{
    if (n == 0)
        return NULL;
    Node *root = NULL;
    root = insert(root, arr[0]);
    for (int i = 1; i < n; i++)
    {
        insert(root, arr[i]);
    }
    return root;
}

void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int arr[] = {10, 5, 1, 7, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = NULL;
    root = pretoin(arr, n);
    inorder(root);
    preorder(root);
    return 0;
}