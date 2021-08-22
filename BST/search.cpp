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

Node *search(Node *root, int key)
{
    if ((root == NULL) || (root->data = key))
        return root;
    if (root->data < key)
        return search(root->right, key);
    return search(root->left, key);
}

Node *insert(Node *root, int key)
{
    if (root == NULL)
    {
        Node *root = new Node(key);
        return root;
    }
    if (root->data > key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node *minvalue(Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node *deleter(Node *root, int key)
{

    if (root == NULL)
        return root;
    else if (root->data < key)
        root->right = deleter(root->right, key);
    else if (root->data > key)
        root->left = deleter(root->left, key);
    else
    {
        Node *temp;
        if (root->left == NULL)
        {
            temp = root->right;
            delete (root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            delete (root);
            return temp;
        }
        else
        {
            temp = minvalue(root->right);
            root->data = temp->data;
            root->right = deleter(root->right, temp->data);
        }
    }
    return root;
}

int main()
{
    Node *root = NULL;
    //root = new Node(10);
    root = insert(root, 10);
    root->left = new Node(4);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right = new Node(16);
    root->right->left = new Node(11);
    root->right->right = new Node(17);
    insert(root, 0);

    //cout << search(root, 5)->data << endl;
    inorder(root);
    deleter(root, 10);
    cout << endl;
    inorder(root);
    return 0;
}