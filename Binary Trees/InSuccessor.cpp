#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node *next;
    Node(int key)
    {
        data = key;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

Node *InSuc(Node *node)
{
    if (node == NULL)
        return NULL;
    Node *suc = node->right;
    while (suc->left != NULL)
        suc = suc->left;
    return suc;
}

void link(Node *root)
{
    if (root == NULL)
        return;
    root->next = InSuc(root);
    link(root->left);

    link(root->right);
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
    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(12);
    root->left->left = new Node(3);

    // Populates nextRight pointer in all nodes
    //link(root);

    /* Let us see the populated values
    Node *ptr = root->left->left;
    while (ptr)
    {
        // -1 is printed if there is no successor
        cout << "Next of " << ptr->data << " is "
             << (ptr->next ? ptr->next->data : -1)
             << endl;
        ptr = ptr->next;
    }
    */
    Node *r = InSuc(root);
    cout << r->data;
    return 0;
}
