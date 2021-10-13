#include <iostream>
using namespace std;

class QueueNode
{
public:
    int val;
    QueueNode *next;
    QueueNode(int data)
    {
        val = data;
        next = NULL;
    }
};
class Queue
{
public:
    QueueNode *front;
    QueueNode *rear;
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    bool isEmpty()
    {
        if (front == NULL && rear == NULL)
            return 1;
        return 0;
    }
    void enqueue(int data)
    {
        QueueNode *node = new QueueNode(data);
        if (isEmpty())
        {
            front = node;
            rear = node;
        }
        else
        {
            rear->next = node;
            rear = node;
        }
    }
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return INT_MIN;
        }
        int ans = front->val;
        front = front->next;
        return ans;
    }
    void display()
    {
        QueueNode *temp = front;
        if (isEmpty())
            cout << "Queue is empty" << endl;
        else
        {
            cout << "Elements in the queue are: ";
            while (temp != rear)
            {
                cout << temp->val << " ";
                temp = temp->next;
            }
            cout << temp->val << endl;
        }
    }
    int peek()
    {
        if (front != NULL)
        {
            cout << "Front element of the queue is: ";
            return front->val;
        }
        cout << "Queue is empty" << endl;
        return INT_MIN;
    }
};

int main()
{
    Queue s;

    s.enqueue(9);
    s.enqueue(10);
    s.display();
    s.enqueue(12);
    s.enqueue(12);
    s.enqueue(12);
    s.display();
    cout << s.peek() << endl;
    s.dequeue();
    s.dequeue();
    s.dequeue();
    s.display();
    return 0;
}