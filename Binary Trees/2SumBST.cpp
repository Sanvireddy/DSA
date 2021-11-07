#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    int val;
};

void inorder(TreeNode *A, unordered_map<int, int> *m, int B, bool *kind)
{
    if (A == NULL || (*kind))
        return;
    inorder(A->left, m, B, kind);
    if ((*m).find(A->val) == (*m).end())
    {
        if ((*m).find(B - (A->val)) == (*m).end())
            (*m)[B - (A->val)]++;
    }
    else
    {
        (*kind) = (true);
        return;
    }
    inorder(A->right, m, B, kind);
}

int t2Sum(TreeNode *A, int B)
{
    unordered_map<int, int> m;
    bool op = 0;
    inorder(A, &m, B, &op);
    if (op)
        return 1;
    return 0;
}