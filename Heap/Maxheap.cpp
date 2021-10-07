#include <bits/stdc++.h>
using namespace std;

class Maxheap
{
    int *harr;
    int heapsize;
    int capacity;

public:
    Maxheap(int capacity);
    void MaxHeapify(int i);
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return ((2 * i) + 1); }
    int right(int i) { return ((2 * i) + 2); }
    int extractMax();
    void IncreaseKey(int i, int new_val);
    int getMax() { return harr[0]; }
    void deleteKey(int i);
    void insertKey(int key);
    void getUnsortedArray();
    void heapsort();
    void printarray();
};

Maxheap::Maxheap(int cap)
{
    harr = new int[cap];
    heapsize = cap;
    capacity = cap;
}

void Maxheap::MaxHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;
    if ((l < heapsize) && (harr[l] > harr[largest]))
        largest = l;
    if ((r < heapsize) && (harr[r] > harr[largest]))
        largest = r;
    if (largest != i)
    {
        swap(harr[largest], harr[i]);
        MaxHeapify(largest);
    }
}

int Maxheap::extractMax()
{
    if (heapsize == 0)
        return INT_MAX;
    if (heapsize == 1)
    {
        heapsize--;
        return harr[0];
    }
    int root = harr[0];
    harr[0] = harr[heapsize - 1];
    heapsize--;
    MaxHeapify(0);
    return root;
}

void Maxheap::IncreaseKey(int i, int new_value)
{
    harr[i] = new_value;
    while (i != 0 && harr[i] > harr[parent(i)])
    {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

void Maxheap::deleteKey(int i)
{
    IncreaseKey(i, INT_MAX);
    int k = extractMax();
}

void Maxheap::insertKey(int key)
{
    if (heapsize == capacity)
    {
        cout << "Overloaded\n";
    }
    harr[heapsize] = key;
    int i = heapsize;
    heapsize++;
    while (i != 0 && (harr[i] > harr[parent(i)]))
    {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

void Maxheap::getUnsortedArray()
{
    int s = capacity;
    cout << "Enter " << s << " no.of elements: \n";
    for (int i = 0; i < s; i++)
    {
        cin >> harr[i];
    }
}

void Maxheap::printarray()
{
    int n = capacity;
    for (int i = 0; i < n; i++)
    {
        cout << harr[i] << " ";
    }
    cout << endl;
}

void Maxheap::heapsort()
{
    int n = heapsize;

    for (int i = ((n / 2) - 1); i >= 0; i--)
    {
        MaxHeapify(i);
    }
    for (int i = 0; i < n; i++)
    {
        harr[n - i - 1] = extractMax();
    }
}

int main()
{
    int s;
    cin >> s;
    Maxheap h(s);
    h.getUnsortedArray();
    int k;
    cin >> k;
    for (int i = ((s / 2) - 1); i >= 0; i--)
        h.MaxHeapify(i);
    int p = 1;
    for (int i = 0; i < 3; i++)
    {
        int y = (h.extractMax());

        p = p * y;
    }
    cout << p << endl;
    return 0;
}