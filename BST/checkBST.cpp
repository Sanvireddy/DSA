#include <bits/stdc++.h>
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

int minValue(Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

int maxValue(Node *root)
{
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

bool isBST(Node *root, int min, int max)
{
    if (root == NULL)
        return true;
    if ((root->left != NULL) && (root->data < maxValue(root->left)))
        return false;
    if ((root->right != NULL) && (root->data > minValue(root->right)))
        return false;
    return (isBST(root->right, min, max) && isBST(root->left, min, max));
}

bool isBSTr(Node *root, int min, int max)
{
    if (root == NULL)
        return true;
}

int main()
{
    Node *root = new Node(3);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(4);

    if (isBSTr(root, INT_MIN, INT_MAX))
        cout << "Is BST";
    else
        cout << "Not a BST";

    return 0;
}
