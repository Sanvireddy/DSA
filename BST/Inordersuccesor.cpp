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

//recursive method
void prefindsuc(Node *root, Node **pre, Node **suc, int key)
{
    if (root == NULL)
        return;
    if (root->data == key)
    {
        if (root->left != NULL)
        {
            Node *temp = root->left;
            while (temp->right != NULL)
                temp = temp->right;
            *pre = temp;
        }
        if (root->right != NULL)
        {
            Node *temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;
            *suc = temp;
        }
        return;
    }

    if (root->data > key)
    {
        *suc = root;
        prefindsuc(root->left, pre, suc, key);
    }
    else
    {
        *pre = root;
        prefindsuc(root->right, pre, suc, key);
    }
}

//recursive inorder traversal method
void findpresuc(Node *root, Node **pre, Node **suc, int key)
{
    if (root == NULL)
        return;
    findpresuc(root->left, pre, suc, key);
    if (root->data > key)
    {
        if ((!*suc) || (*suc)->data > root->data)
            (*suc) = root;
    }
    else if (root->data < key)
    {
        if ((!*pre) || (*pre)->data > root->data)
            (*pre) = root;
    }

    findpresuc(root->right, pre, suc, key);
}

Node *insert(Node *root, int key)
{
    if (root == NULL)
    {
        Node *root = new Node(key);
        return root;
    }
    if (root->data > key)
    {
        root->left = insert(root->left, key);
    }
    else
    {
        root->right = insert(root->right, key);
    }
}

int main()
{
    int key = 70;
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    Node *pre = NULL;
    Node *suc = NULL;
    prefindsuc(root, &pre, &suc, key);
    if (pre == NULL)
        cout << "NO PREDECESSOR\n";
    else
        cout << "PREDECESSOR IS " << (pre)->data << endl;
    if (suc == NULL)
        cout << "NO SUCCESSOR\n";
    else
        cout << "SUCCESSOR IS " << (suc)->data << endl;
    return 0;
}