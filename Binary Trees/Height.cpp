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

int height(Node *root)
{
    if (root == NULL)
        return -1;
    int lheight = height(root->left);
    int rheight = height(root->right);
    if (lheight > rheight)
        return lheight + 1;
    else
        return rheight + 1;
}

int main()
{
    Node *root = new Node(30);
    root->left = new Node(18);
    root->left->left = new Node(10);
    root->right = new Node(43);
    root->right->right = new Node(48);
    root->right->left = new Node(32);
    root->left->right = new Node(25);
    root->left->left->left = new Node(89);
    cout << "Height of tree is: " << height(root) << endl;
    return 0;
}