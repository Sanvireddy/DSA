#include <bits/stdc++.h>
using namespace std;
#define V 5
#define E 8

void addEdge(int adj[][E], int u, int v, int e)
{
    adj[u][e] = 1;
    if (u != v)
        adj[v][e] = -1;
}

int main()
{
    int adj[V][E] = {0};
    addEdge(adj, 0, 1, 0);
    addEdge(adj, 0, 4, 1);
    addEdge(adj, 1, 4, 2);
    addEdge(adj, 1, 3, 3);
    addEdge(adj, 3, 4, 4);
    addEdge(adj, 3, 2, 7);
    addEdge(adj, 1, 1, 5);
    addEdge(adj, 1, 2, 6);
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < E; j++)
            cout << adj[i][j] << "    ";
        cout << endl;
    }
    return 0;
}