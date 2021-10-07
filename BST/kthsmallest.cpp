#include <bits/stdc++.h>
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
int usingMI(Node *root, int k)
{
    if (root == NULL)
        return -1;
    int count = 0;
    Node *current = root;
    int ksmall = INT_MIN;
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            count++;
            if (count == k)
                ksmall = current->data;
            current = current->right;
        }
        else
        {
            Node *pre = current->left;
            while (pre->right != NULL && pre->right != current)
                pre = pre->right;
            if (pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }
            else
            {
                pre = NULL;
                count++;
                if (count == k)
                    ksmall = current->data;
                current = current->right;
            }
        }
    }
    return ksmall;
}

int main()
{
    Node *root = new Node(20);
    root->left = new Node(8);
    root->left->left = new Node(4);
    root->right = new Node(22);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    cout << usingMI(root, 8) << endl;
    return 0;
}