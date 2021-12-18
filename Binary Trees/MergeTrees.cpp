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

Node *solve(Node *A, Node *B)
{
    if (A == NULL)
        return B;
    if (B == NULL)
        return A;
    A->data += B->data;
    A->right = solve(A->right, B->right);
    A->left = solve(A->left, B->left);
    return A;
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
    // inorder(root1);
    Node *root2 = new Node(2);
    root2->right = new Node(1);
    root2->left = new Node(1);
    root2->right->left = new Node(2);
    root2->left->right = new Node(5);
    root2->left->left = new Node(5);
    // inorder(root2);
    inorder(solve(root1, root2));
    return 0;
}