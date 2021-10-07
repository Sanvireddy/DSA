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

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

//recursive
void mirrorR(Node *root)
{
    if (root == NULL)
        return;
    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirrorR(root->left);
    mirrorR(root->right);
}

//iterative
void mirrorI(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    Node *temp = NULL;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        swap(temp->right, temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
        if (temp->left != NULL)
            q.push(temp->left);
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    root->right->left = new Node(5);
    root->right->right = new Node(4);
    cout << "Inorder traversal of the constructed tree is: " << endl;
    inorder(root);
    cout << endl;
    mirrorR(root);
    cout << "Inorder traversal of the mirror tree(recursive) is: " << endl;
    inorder(root);
    cout << endl;
    mirrorI(root);
    cout << "Inorder traversal of the mirror tree(iterative) is: " << endl;
    inorder(root);
    return 0;
}