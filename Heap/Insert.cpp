#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
    int capacity;
    int heapsize;
    int *harr;

public:
    MinHeap(int capacity);
    void MinHeapify(int i);
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return ((2 * i) + 1); }
    int right(int i) { return ((2 * i) + 2); }
    int extractMin();
    void decreaseKey(int i, int new_val);
    int getMin() { return harr[0]; }
    void deleteKey(int i);
    void insertKey(int key);
    void getUnsortedArray();
    void heapsort();
    void printarray();
};

MinHeap::MinHeap(int cap)
{
    heapsize = cap;
    capacity = cap;
    harr = new int[cap];
}

void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if ((l < heapsize) && (harr[l] < harr[i]))
        smallest = l;
    if ((r < heapsize) && (harr[r] < harr[smallest]))
        smallest = r;
    if (smallest != i)
    {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}

int MinHeap::extractMin()
{
    if (heapsize <= 0)
        return INT_MAX;
    if (heapsize == 1)
    {
        heapsize--;
        return harr[0];
    }
    int root = harr[0];
    harr[0] = harr[heapsize - 1];
    heapsize--;
    MinHeapify(0);
    return root;
}

void MinHeap::insertKey(int key)
{
    if (heapsize == capacity)
    {
        cout << "Overflow\n";
        return;
    }
    harr[heapsize] = key;
    heapsize++;
    int i = heapsize - 1;
    while ((i > 0) && (harr[parent(i)] > harr[i]))
    {
        swap(harr[parent(i)], harr[i]);
        i = parent(i);
    }
}

void MinHeap::decreaseKey(int i, int new_value)
{
    harr[i] = new_value;
    while (i != 0 && (harr[i] < harr[parent(i)]))
    {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
    return;
}

void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    int k = extractMin();
    return;
}

void MinHeap::getUnsortedArray()
{
    cout << "Enter " << capacity << " no.of elements: " << endl;
    for (int i = 0; i < capacity; i++)
    {
        cin >> harr[i];
    }
}

void MinHeap::heapsort()
{
    int temp[capacity];
    for (int i = 0; i < heapsize; i++)
    {
        temp[i] = extractMin();
        cout << temp[i] << " ";
    }
}

void MinHeap::printarray()
{
    for (int i = 0; i < heapsize; i++)
        cout << harr[i] << " ";
    cout << endl;
}

int main()
{
    int s;
    cin >> s;
    MinHeap heap(s);
    heap.getUnsortedArray();
    heap.printarray();
    for (int i = ((s / 2) - 1); i >= 0; i--)
    {
        heap.MinHeapify(i);
    }
    heap.deleteKey(2);
    heap.printarray();

    return 0;
}
