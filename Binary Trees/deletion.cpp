#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);

    cout << root->data << " ";
    inorder(root->right);
}

void deletedeepest(Node *root, Node *dnode)
{

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == dnode)
        {
            temp = NULL;
            delete (dnode);
            return;
        }
        if (temp->left)
        {
            temp = NULL;
            delete (dnode);
            return;
        }
        else
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            temp = NULL;
            delete (dnode);
            return;
        }
        else
        {
            q.push(temp->right);
        }
    }
}

Node *deletenode(Node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL)
    {
        if (root->data == key)
        {
            return NULL;
        }
        else
            return root;
    }

    queue<Node *> q;
    q.push(root);
    Node *keynode = NULL;
    Node *lastnode = NULL;
    while (!q.empty())
    {
        lastnode = q.front();
        q.pop();
        if (lastnode->data == key)
            keynode = lastnode;
        if (lastnode->left)
            q.push(lastnode->left);
        if (lastnode->right)
            q.push(lastnode->right);
    }

    if (keynode != NULL)
    {
        int x = lastnode->data;
        deletedeepest(root, lastnode);
        keynode->data = x;
    }
    return root;
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(11);
    root->left->left = new Node(7);
    root->right = new Node(9);
    root->right->left = new Node(15);
    root->right->right = new Node(8);

    cout << "Inorder traversal before deletion: ";
    inorder(root);
    cout << endl;

    int key = 15;

    cout << "Inorder traversal after deletion: ";
    deletenode(root, key);
    inorder(root);
    cout << endl;
    return 0;
}
