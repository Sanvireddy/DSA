#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    Node *next;
    int data;
    Node(int key)
    {
        left = NULL;
        right = NULL;
        next = NULL;
        data = key;
    }
};

void popul(Node *root, Node **pre)
{
    if (root == NULL)
        return;
    popul(root->left, pre);
    if ((*pre) != NULL)
        (*pre)->next = root;
    (*pre) = root;
    popul(root->right, pre);
}

void inorderSuccessor(Node *curr)
{
    Node *prev = nullptr;

    // set next pointer of all nodes
    popul(curr, &prev);

    // go to the leftmost node
    curr = curr->left->left;

    // print inorder successor of all nodes
    while (curr->next)
    {
        cout << "The inorder successor of " << curr->data << " is "
             << curr->next->data << endl;
        curr = curr->next;
    }
}

void populateNext(Node *root)
{
    static Node *next = NULL;
    if (root == NULL)
        return;
    populateNext(root->right);
    root->next = next;
    next = root;
    populateNext(root->left);
}

int main()
{

    /* Constructed binary tree is
            10
            / \
           8   12
         /
        3
    */
    /*
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    inorderSuccessor(root);
    */
    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(12);
    root->left->left = new Node(3);

    // Populates nextRight pointer in all nodes
    populateNext(root);

    // Let us see the populated values
    Node *ptr = root->left->left;
    while (ptr)
    {
        // -1 is printed if there is no successor
        cout << "Next of " << ptr->data << " is "
             << (ptr->next ? ptr->next->data : -1)
             << endl;
        ptr = ptr->next;
    }

    return 0;
}