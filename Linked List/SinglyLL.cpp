#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void push(Node **head, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
}

void insertafter(Node *node, int new_data)
{
    if (node == NULL)
    {
        cout << "Given node cannot be null!\n";
        return;
    }
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = node->next;
    node->next = new_node;
}

void append(Node **head, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = NULL;
    if ((*head) == NULL)
    {
        (*head) = new_node;
        return;
    }
    Node *last = (*head);
    while ((last)->next != NULL)
    {
        (last) = (last)->next;
    }

    (last)->next = new_node;
}

void traversal(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void deleteKey(Node *head, int key)
{
}
int main()
{
    Node *head = NULL;
    append(&head, 6);

    // Insert 7 at the beginning.
    // So linked list becomes 7->6->NULL
    push(&head, 7);

    // Insert 1 at the beginning.
    // So linked list becomes 1->7->6->NULL
    push(&head, 1);

    // Insert 4 at the end. So
    // linked list becomes 1->7->6->4->NULL
    append(&head, 4);

    // Insert 8, after 7. So linked
    // list becomes 1->7->8->6->4->NULL
    insertafter(head->next, 8);

    traversal(head);

    return 0;
}