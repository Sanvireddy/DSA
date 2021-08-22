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

int maxDepth(Node *root)
{
    if (root == NULL)
        return 0;
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    if (lh > rh)
        return lh + 1;
    else
        return rh + 1;
}

void printcurrentlevele(Node *root, int level, bool ltr)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1)
    {
        if (ltr)
        {
            printcurrentlevele(root->left, level - 1, ltr);
            printcurrentlevele(root->right, level - 1, ltr);
        }
        else
        {
            printcurrentlevele(root->right, level - 1, ltr);
            printcurrentlevele(root->left, level - 1, ltr);
        }
    }
}

void printSpiralI(Node *root)
{
    if (root == NULL)
        return;
    deque<Node *> q;
    q.push_front(root);
    int nodecount = 0;
    bool ltr = false;
    while (!q.empty())
    {
        nodecount = q.size();
        if (ltr)
        {
            while (nodecount > 0)
            {
                Node *node = q.front();
                cout << node->data << " ";
                q.pop_front();
                if (node->left != NULL)
                    q.push_back(node->left);
                if (node->right != NULL)
                    q.push_back(node->right);
                nodecount--;
            }
        }
        else
        {
            while (nodecount > 0)
            {
                Node *node = q.back();
                cout << node->data << " ";
                q.pop_back();
                if (node->right != NULL)
                    q.push_front(node->right);
                if (node->left != NULL)
                    q.push_front(node->left);

                nodecount--;
            }
        }
        ltr = !ltr;
    }
}

/*
void printcurrentlevelo(Node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1)
    {
        printcurrentlevelo(root->right, level - 1);
        printcurrentlevelo(root->left, level - 1);
    }
}
*/

void printspiral(Node *root)
{
    if (root == NULL)
        return;
    int h = maxDepth(root);
    bool ltr = false;
    for (int i = 1; i <= h; i++)
    {
        printcurrentlevele(root, i, ltr);
        ltr = !ltr;
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);
    root->right->right->right = new Node(12);
    root->right->right->left = new Node(13);
    root->left->right->left = new Node(15);
    root->left->right->right = new Node(14);
    printf("Spiral Order traversal of binary tree is \n");
    printspiral(root);
    printf("\n");
    printf("Spiral Order traversal of binary tree is \n");
    printSpiralI(root);

    return 0;
}