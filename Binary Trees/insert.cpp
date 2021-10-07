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

void insert(Node *root, int key)
{
    queue<Node *> q;
    q.push(root);
    Node *new_node = new Node(key);
    while (!q.empty())
    {
        Node *n = q.front();
        q.pop();
        if (!n->left)
        {
            n->left = new_node;
            return;
        }
        else if (!n->right)
        {
            n->right = new_node;
            return;
        }
        else
        {
            q.push(n->left);
            q.push(n->right);
        }
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(11);
    root->left->left = new Node(7);
    root->right = new Node(9);
    root->right->left = new Node(15);
    root->right->right = new Node(8);
    root->left->right = new Node(11);

    cout << "Inorder traversal before insertion: ";
    inorder(root);
    cout << endl;

    int key = 12;
    insert(root, key);

    cout << "Inorder traversal after insertion: ";
    inorder(root);
    cout << endl;
    return 0;
}