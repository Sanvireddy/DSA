#include <bits/stdc++.h>
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

vector<vector<int>> zigzag(Node *a)
{
    vector<vector<int>> v;
    if (a == NULL)
        return v;
    queue<Node *> q;
    q.push(a);
    bool cnt = 1;
    while (!q.empty())
    {
        int n = q.size();
        vector<int> l;
        while (n--)
        {
            Node *node = q.front();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
            l.push_back(node->data);
            q.pop();
        }
        if (!cnt)
            reverse(l.begin(), l.end());
        v.push_back(l);
        cnt = !cnt;
    }
    return v;
}

int main()
{
    Node *root = new Node(2);
    root->left = new Node(3);
    root->left->left = new Node(5);
    root->left->left->right = new Node(9);
    root->left->left->right->left = new Node(-1);
    root->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<vector<int>> k;
    k = zigzag(root);

    for (int i = 0; i < k.size(); i++)
    {
        for (int j = 0; j < k[i].size(); j++)
            cout << k[i][j] << " ";
        cout << endl;
    }
}