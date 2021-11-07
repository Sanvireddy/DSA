#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    int val;
};

void inorder(TreeNode *root, vector<int> *v)
{
    if (root == NULL)
        return;
    inorder(root->left, v);
    (*v).push_back(root->val);
    inorder(root->right, v);
}
vector<int> recoverTree(TreeNode *A)
{
    vector<int> res;
    vector<int> v;
    int p;
    inorder(A, &v);

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] < v[i - 1])
        {
            res.push_back(v[i - 1]);
            int j = i;
            p = i;
            while (j < (v.size() - 1))
            {
                if (v[j] > v[j + 1])
                {
                    res.push_back(v[j + 1]);
                    break;
                }
                j++;
            }
            break;
        }
    }
    if (res.size() == 1)
        res.push_back(v[p]);
    sort(res.begin(), res.end());
    return res;
}
