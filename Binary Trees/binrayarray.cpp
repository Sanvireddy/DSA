#include <iostream>
using namespace std;

char tree[10];

int root(char key)
{
    if (tree[0] != '\0')
        cout << "Tree already had root!" << endl;

    else
        tree[0] = key;

    return 0;
}

int set_right(char key, int parent)
{
    if (tree[parent] == '\0')
    {
        cout << "Cannot set right child since parent is NULL" << endl;
        return 0;
    }
    if (tree[(2 * parent + 2)] == '\0')
        tree[(2 * parent + 2)] = key;
    else
        cout << "It already has a right child!";

    return 0;
}

int set_left(char key, int parent)
{
    if (tree[parent] == '\0')
    {
        cout << "Cannot set left child since parent is NULL" << endl;
        return 0;
    }
    if (tree[(2 * parent + 1)] == '\0')
        tree[(2 * parent + 1)] = key;
    else
        cout << "It already has a left child!";
    return 0;
}

int print_tree()
{
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        if (tree[i] == '\0')
            cout << "-";
        else
            cout << tree[i];
    }
    return 0;
}

int main()
{
    root('A');
    //insert_left('B',0);
    set_right('C', 0);
    set_left('D', 1);
    set_right('E', 1);
    set_right('F', 2);
    print_tree();
    return 0;
}
