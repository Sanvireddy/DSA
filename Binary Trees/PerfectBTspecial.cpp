#include <iostream>
#include <deque>
#include <vector>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int data;
};

Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->right = node->left = NULL;
    return node;
}

void print(Node *root)
{
    if (root == NULL)
        return;
    deque<Node *> d;

    d.push_front(root);
    int nc = 0;
    Node *n;
    cout << root->data << " ";
    while (!d.empty())
    {
        nc = d.size();

        Node *node;
        bool ltr = true;
        deque<Node *> d2;
        while (nc > 0)
        {
            node = d.front();
            d.pop_front();

            if (node->left)
                d2.push_back(node->left);
            if (node->right)
                d2.push_back(node->right);
            nc--;
        }
        d = d2;
        while (!d2.empty())
        {
            if (ltr)
            {
                n = d2.front();
                cout << n->data << " ";
                d2.pop_front();
            }
            else
            {
                n = d2.back();
                cout << n->data << " ";
                d2.pop_back();
            }
            ltr = !ltr;
        }
    }
}

int main()
{
    //Perfect Binary Tree of Height 4
    Node *root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);

    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(11);
    root->right->left->left = newNode(12);
    root->right->left->right = newNode(13);
    root->right->right->left = newNode(14);
    root->right->right->right = newNode(15);

    root->left->left->left->left = newNode(16);
    root->left->left->left->right = newNode(17);
    root->left->left->right->left = newNode(18);
    root->left->left->right->right = newNode(19);
    root->left->right->left->left = newNode(20);
    root->left->right->left->right = newNode(21);
    root->left->right->right->left = newNode(22);
    root->left->right->right->right = newNode(23);
    root->right->left->left->left = newNode(24);
    root->right->left->left->right = newNode(25);
    root->right->left->right->left = newNode(26);
    root->right->left->right->right = newNode(27);
    root->right->right->left->left = newNode(28);
    root->right->right->left->right = newNode(29);
    root->right->right->right->left = newNode(30);
    root->right->right->right->right = newNode(31);

    cout << "Specific Level Order traversal of binary tree is \n";
    print(root);

    return 0;
}