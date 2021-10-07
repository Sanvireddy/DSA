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

void morrisTraversal(Node *root)
{
    if (root == NULL)
        return;
    Node *predecessor = NULL;
    while (root != NULL)
    {
        if (root->left != NULL)
        {
            predecessor = root->left;
            while (predecessor->right != NULL && predecessor->right != root)
            {
                predecessor = predecessor->right;
            }

            if (predecessor->right == NULL)
            {
                predecessor->right = root;

                root = root->left;
            }
            else
            {
                predecessor->right = NULL;
                cout << root->data << " ";
                root = root->right;
            }
        }
        else
        {
            cout << root->data << " ";
            root = root->right;
        }
    }
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
    morrisTraversal(root);

    return 0;
}
