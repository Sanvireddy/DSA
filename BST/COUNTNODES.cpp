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

void countNodes(Node *root, int *k)
{
    if (root == NULL)
        return;
    countNodes(root->left, k);
    *k += 1;
    countNodes(root->right, k);
}

int countnodes(Node *root)
{
    int k = 0;
    countNodes(root, &k);
    return k;
}

Node *find_kth_smallest(Node *root, int &count, int k)
{
    if (root == NULL)
        return NULL;
    Node *left = find_kth_smallest(root->left, count, k);
    if (left != NULL)
        return left;
    count++;
    if (count == k)
        return root;
    return find_kth_smallest(root->right, count, k);
}

int elementPos(Node *root, int k)
{
    int count = 0;
    return find_kth_smallest(root, count, k)->data;
}

int getmedian(Node *root)
{
    if ((countnodes(root) % 2) == 0)
        return ((elementPos(root, (countnodes(root) + 2) / 2) + elementPos(root, ((countnodes(root) + 1) / 2))) / 2);
    else
        return elementPos(root, (countnodes(root) + 1) / 2);
}

int main()
{
    Node *root2 = new Node(6);
    root2->left = new Node(3);
    root2->left->left = new Node(1);
    root2->left->right = new Node(4);
    //root2->left->right->left = new Node(10);
    //root2->left->right->right = new Node(14);
    root2->right = new Node(8);
    root2->right->left = new Node(7);
    root2->right->right = new Node(9);

    cout << countnodes(root2) << endl;
    int k = countnodes(root2) / 2;
    cout << k << endl;
    cout << elementPos(root2, 1) << endl;
    cout << "Median is " << getmedian(root2);
    return 0;
}