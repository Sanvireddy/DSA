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

void findnthNodeInorder(Node *root, int n)
{
    static int k = 0;
    if (root == NULL)
        return;

    findnthNodeInorder(root->left, n);
    k++;
    if (k == n)
        cout << root->data << endl;
    findnthNodeInorder(root->right, n);
}

void findnthPostorder(Node *root, int n)
{
    static int count = 0;
    if (root == NULL)
        return;

    findnthPostorder(root->left, n);
    findnthPostorder(root->right, n);
    count++;
    if (count == n)
        cout << root->data << endl;
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    int n = 2;
    Node *root1 = new Node(25);
    root1->left = new Node(20);
    root1->right = new Node(30);
    root1->left->left = new Node(18);
    root1->left->right = new Node(22);
    root1->right->left = new Node(24);
    root1->right->right = new Node(32);

    int N = 2;

    findnthNodeInorder(root, n);
    findnthPostorder(root1, N);
    return 0;
}