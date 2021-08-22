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

void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int findpredecessor(Node *node)
{
    if (node == NULL)
        return -10;

    while (node->left != NULL)
        node = node->left;
    while (node->right != NULL)
        node = node->right;
    return node->data;
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

    cout << "Inorder traversal: ";
    inorder(root);
    cout << "Predecessor: " << findpredecessor(root->left) << endl;
    return 0;
}