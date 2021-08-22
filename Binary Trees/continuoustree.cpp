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

bool isContinuous(Node *root)
{
    if (root == NULL)
        return true;
    queue<Node *> q;
    q.push(root);
    Node *temp = NULL;
    int flag = 0;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp->right != NULL)
        {
            q.push(temp->right);
            if (abs(temp->data - temp->right->data) == 1)
                flag = 1;
            else
            {
                flag = 0;
                break;
            }
        }
        else
            flag = 1;
        if (temp->left != NULL)
        {
            q.push(temp->left);
            if (abs(temp->data - temp->left->data) == 1)
                flag = 1;
            else
            {
                flag = 0;
                break;
            }
        }
        else
            flag = 1;
    }

    if (flag)
        return true;
    else
        return false;
}

int main()
{
    struct Node *root = new Node(7);
    root->left = new Node(5);
    root->right = new Node(8);
    root->left->left = new Node(10);
    root->right->right = new Node(6);
    root->right->left = new Node(4);
    isContinuous(root) ? cout << "Yes" : cout << "No";
    return 0;
}
