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

void printcurrentlevel(Node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1)
    {
        printcurrentlevel(root->left, level - 1);
        printcurrentlevel(root->right, level - 1);
    }
}
int maxD(Node *root)
{
    if (root == NULL)
        return 0;
    int lh = maxD(root->left);
    int rh = maxD(root->right);
    if (lh > rh)
        return lh + 1;
    else
        return rh + 1;
}

void reverseTraversal(Node *root)
{
    int height = maxD(root);
    while (height > 0)
    {
        printcurrentlevel(root, height);
        height--;
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);

    printf("Level Order traversal of binary tree is \n");
    printcurrentlevel(root, 4);
    cout << "\nReverse Level Order traversal: ";
    reverseTraversal(root);
    return 0;
}