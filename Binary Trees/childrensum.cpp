#include <iostream>
#include <queue>
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

bool isSumProp(Node *root)
{
    int ldata = 0;
    int rdata = 0;
    if (root == NULL || ((root->left == NULL) && (root->right == NULL)))
        return true;
    if (root->left)
    {
        ldata = root->left->data;
    }
    if (root->right)
        rdata = root->right->data;
    if (root->data != (rdata + ldata))
        return false;
    isSumProp(root->left);
    isSumProp(root->right);
    return true;
}
bool isChildrenSum(Node *root)
{
    if (root == NULL)
        return true;
    Node *node = root;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        node = q.front();
        q.pop();
        int k = 0;
        if (node->left)
        {
            q.push(node->left);
            k += node->left->data;
        }
        if (node->right)
        {
            q.push(node->right);
            k += node->right->data;
        }
        if ((node->left != NULL) || (node->right != NULL))
        {
            if (k != node->data)
                return false;
            cout << k << " " << node->data << endl;
        }
    }
    return true;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(2);
    if (isSumProp(root))
        cout << "The given tree satisfies "
             << "the children sum property\n ";
    else
        cout << "The given tree does not satisfy "
             << "the children sum property\n ";

    return 0;
}