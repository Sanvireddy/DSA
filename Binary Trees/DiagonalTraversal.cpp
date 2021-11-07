#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    int val;
};

vector<int> solve(TreeNode *A)
{
    queue<TreeNode *> q;
    vector<int> v;
    if (A == NULL)
        return v;
    TreeNode *node = A;
    while (node != NULL)
    {
        q.push(node);
        node = node->right;
    }
    while (!q.empty())
    {
        node = q.front();
        q.pop();
        v.push_back(node->val);
        node = node->left;
        while (node != NULL)
        {
            q.push(node);
            node = node->right;
        }
    }
    return v;
}

int main()
{
    return 0;
}
