#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    int val;
};

TreeNode *newNode(int data)
{
    TreeNode *temp = new TreeNode();
    temp->val = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

bool is(TreeNode *a, TreeNode *b)
{
    if (a == NULL && b == NULL)
        return 1;
    if ((a == NULL && b != NULL) || (a != NULL && b == NULL))
        return 0;
    if (a->val == b->val)
        return (is(a->left, b->right) && is(a->right, b->left));
    return 0;
}

int isSymmetric(TreeNode *A)
{
    if (A == NULL)
        return 1;
    return is(A->left, A->right);
}

int main()
{
    TreeNode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);

    if (isSymmetric(root))
        cout << "Symmetric";
    else
        cout << "Not symmetric";
    return 0;
}
