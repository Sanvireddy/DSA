#include <iostream>
#include <vector>
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

void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

vector<Node *> gettrees(int arr[], int start, int end)
{
    vector<Node *> trees;
    if (start > end)
    {
        trees.push_back(NULL);
        return trees;
    }

    for (int i = start; i <= end; i++)
    {
        vector<Node *> ltrees = gettrees(arr, start, i - 1);
        vector<Node *> rtrees = gettrees(arr, i + 1, end);
        for (int j = 0; j < ltrees.size(); j++)
        {
            for (int k = 0; k < rtrees.size(); k++)
            {
                Node *node = new Node(arr[i]);
                node->left = ltrees[j];
                node->right = rtrees[k];
                trees.push_back(node);
            }
        }
    }
    return trees;
}

int main()
{
    int in[] = {4, 5, 7};
    int n = sizeof(in) / sizeof(in[0]);

    vector<Node *> trees = gettrees(in, 0, n - 1);

    cout << "Preorder traversals of different "
         << "possible Binary Trees are \n";
    for (int i = 0; i < trees.size(); i++)
    {
        preorder(trees[i]);
        printf("\n");
    }
    return 0;
}