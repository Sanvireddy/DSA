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

Node *merge(Node *root1, Node *root2)
{
    if (root1 == NULL)
    {
        if (root2 == NULL)
            return root1;
        else
            root1 = root2;
    }
    else
    {
        if (root2 != NULL)
        {
            root1->data += root2->data;
            root1->left = merge(root1->left, root2->left);
            root1->right = merge(root1->right, root2->right);
        }
    }
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root1 = new Node(1);
    root1->right = new Node(2);
    root1->left = new Node(3);
    root1->right->left = new Node(7);
    root1->right->right = new Node(2);
    root1->left->left = new Node(1);
    //inorder(root1);
    Node *root2 = new Node(2);
    root2->right = new Node(1);
    root2->left = new Node(1);
    root2->right->left = new Node(2);
    root2->left->right = new Node(5);
    root2->left->left = new Node(5);
    //inorder(root2);
    inorder(merge(root1, root2));
    return 0;
}