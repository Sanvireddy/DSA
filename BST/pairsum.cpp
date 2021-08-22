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

int getsum(Node *root1, Node *root2, int x, int *k)
{
    if (root1 == NULL || root2 == NULL)
        return *k;
    if ((root1->data + root2->data) < x)
    {
        (*k) = getsum(root1->right, root2, x, k);
        (*k) = getsum(root1, root2->right, x, k);
    }
    else if ((root1->data + root2->data) > x)
    {
        (*k) = getsum(root1->left, root2, x, k);
        (*k) = getsum(root1, root2->left, x, k);
    }
    else
    {
        (*k) += 1;
        (*k) = getsum(root1->left, root2->right, x, k);
        (*k) = getsum(root1->right, root2->left, x, k);
    }

    return (*k);
}

int totsum(Node *root1, Node *root2, int x)
{
    int k = 0;
    return getsum(root1, root2, x, &k);
}

int main()
{

    Node *root1 = new Node(5);
    root1->left = new Node(3);
    root1->left->left = new Node(2);
    root1->left->right = new Node(4);
    root1->right = new Node(7);
    root1->right->left = new Node(6);
    root1->right->right = new Node(8);

    Node *root2 = new Node(10);
    root2->left = new Node(6);
    root2->left->left = new Node(3);
    root2->left->right = new Node(8);
    root2->right = new Node(15);
    root2->right->left = new Node(11);
    root2->right->right = new Node(18);
    int x = 16;
    /*
    Node *root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(3);
    Node *root2 = new Node(3);
    root2->left = new Node(2);
    root2->right = new Node(4);
*/
    cout << totsum(root1, root2, x) << endl;

    //cout << checking(&k);

    return 0;
}