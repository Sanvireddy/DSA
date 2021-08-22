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

void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    Node *root = new Node(2);
    root->left = new Node(3);
    root->left->left = new Node(5);
    root->left->left->right = new Node(9);
    root->left->left->right->left = new Node(-1);
    root->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout << "Preorder traversal: ";
    preorder(root);
    return 0;
}