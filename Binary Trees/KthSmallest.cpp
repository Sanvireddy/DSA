#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};
void inorder(TreeNode *A, vector<int>* v)
{
    if (A == NULL)
        return;
    inorder(A->left, v);
    (*v).push_back(A->val);
    inorder(A->right, v);
    return;
}
int kthsmallest(TreeNode *A, int B)
{
    vector<int> v;
    inorder(A, &v);
    return v[B - 1];
}
TreeNode *insert(TreeNode *node, int x)
{
    if (node == NULL)
    {
        node = new TreeNode(x);
    }
    if (x < node->val)
        node->left = insert(node->left, x);
    if (x > node->val)
        node->right = insert(node->right, x);
    return node;
}
int main()
{
    int keys[] = {20, 8, 22, 4, 12, 10, 14};
    TreeNode *root = NULL;
    for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++)
        root = insert(root, keys[i]);
    cout << kthsmallest(root, 4) << endl;
    cout<<endl;
    int x=1300+1100+500+600+500+300+300+600+300+700+300+300+300+500+300+300+900
+300+300+300+500+300+300+300+300+900+300+300+600+300+300+300+300+300+300+300+300+
300+300+300+300+300+300+300+300+300+300+300+300+300+300+300+500+300+2000+300+300+300+
300+300+300+500+300+500+300+300;
cout<<x<<endl;
    return 0;
}
