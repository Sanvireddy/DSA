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

void kthlargest(Node *root, int k, int &c)
{
    if (root == NULL || (c) >= k)
        return;

    kthlargest(root->right, k, c);
    (c)++;
    if ((c) == k)
    {
        cout << root->data << " ";
        return;
    }
    kthlargest(root->left, k, c);
}

void kl(Node *root, int k)
{
    int c = 0;
    kthlargest(root, k, c);
    return;
}

int main()
{
    Node *root = new Node(12);
    root->left = new Node(10);
    root->right = new Node(16);
    root->left->left = new Node(6);
    root->left->right = new Node(11);
    root->left->left->right = new Node(8);
    root->left->left->left = new Node(4);
    root->right->right = new Node(18);
    root->right->left = new Node(13);
    root->right->right->left = new Node(17);
    root->right->right->right = new Node(21);
    int key;
    int k = 1;
    kl(root, k);
    return 0;
}