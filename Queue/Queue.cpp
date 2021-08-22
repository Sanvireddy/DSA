#include <iostream>
using namespace std;

class Queue
{
private:
    int *arr;
    int front;
    int rear;
    int size;

public:
    Queue(int cap)
    {
        arr = new int[cap];
        front = -1;
        rear = -1;
        size = cap;
    }
    bool isEmpty()
    {
        if ((rear == -1) && (front == -1))
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if (rear == (size - 1))
            return true;
        else
            return false;
    }

    void enqueue(int key)
    {
        if (isFull())
            return;
        else if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = key;
        return;
    }

    int dequeue()
    {
        int x;
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return 0;
        }
        else if (rear == front)
        {
            x = arr[front];
            arr[front] = 0;
            rear = -1;
            front = -1;
        }
        else
        {
            x = arr[front];
            arr[front] = 0;
            front++;
        }
        return x;
    }

    void display()
    {
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int getrear()
    {
        return rear;
    }

    int getfront()
    {
        return front;
    }
};

int main()
{
    Queue q(4);
    cout << q.isEmpty() << endl;
    cout << q.isFull() << endl;
    q.enqueue(7);
    q.display();

    q.enqueue(2);
    q.display();
    //cout << "1. " << q.getfront() << endl;
    //cout << "2. " << q.getrear() << endl;
    q.enqueue(3);
    q.display();
    q.enqueue(0);
    q.enqueue(9);
    cout << q.isFull() << endl;
    //cout << "1. " << q.getfront() << endl;
    //cout << "2. " << q.getrear() << endl;
    cout << q.dequeue() << endl;
    cout << "1. " << q.getfront() << endl;
    cout << "2. " << q.getrear() << endl;
    q.display();
    return 0;
}