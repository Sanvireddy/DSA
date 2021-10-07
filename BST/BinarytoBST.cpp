#include <iostream>
#include <vector>
#include <algorithm>

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

void printinorder(Node *root)
{
    if (root == NULL)
        return;
    printinorder(root->left);
    cout << (root->data) << " ";
    printinorder(root->right);
}

void inorder(Node *root, vector<int> &v)
{
    if (root == NULL)
        return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int countnodes(Node *root)
{
    static int k = 0;
    if (root == NULL)
        return 0;
    countnodes(root->left);
    k++;
    countnodes(root->right);
}

void inchange(Node *root, vector<int> v)
{
    if (root == NULL)
        return;
    static int index = 0;
    inchange(root->left, v);
    root->data = v[index];
    index++;
    inchange(root->right, v);
}

Node *binaryTreeToBST(Node *root)
{
    if (root == NULL)
        return root;
    vector<int> v;
    inorder(root, v);
    sort(v.begin(), v.end());
    inchange(root, v);
    return root;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->right = new Node(3);
    cout << countnodes(root) << endl;
    Node *root1 = binaryTreeToBST(root);
    cout << root1->right->data << " ";
    return 0;
}