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

class ListNode
{
public:
    int data;
    ListNode *next;
};

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node *binaryTree(ListNode *head)
{
    if (head == NULL)
        return NULL;
    queue<Node *> q;
    Node *root = new Node(head->data);
    q.push(root);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (head->next)
        {
            head = head->next;
            node->left = new Node(head->data);
            q.push(node->left);
        }
        if (head->next)
        {
            head = head->next;
            node->right = new Node(head->data);
            q.push(node->right);
        }
    }
    return root;
}

void push(ListNode **head, int key)
{
    ListNode *node = new ListNode();
    node->data = key;
    node->next = (*head);
    (*head) = node;
}

int main()
{
    // create a linked list shown in above diagram
    struct ListNode *head = NULL;
    push(&head, 36); /* Last node of Linked List */
    push(&head, 30);
    push(&head, 25);
    push(&head, 15);
    push(&head, 12);
    push(&head, 36);
    push(&head, 30);
    push(&head, 25);
    push(&head, 15);
    push(&head, 12);
    push(&head, 10); /* First node of Linked List */

    Node *root;
    root = binaryTree(head);
    cout << "Inorder Traversal of the constructed Binary Tree is: \n";
    inorder(root);
    return 0;
}
