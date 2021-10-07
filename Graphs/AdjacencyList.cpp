#include <bits/stdc++.h>
using namespace std;

#define V 5

void addEdge(vector<pair<int, int>> adj[], int u, int v, int weight)
{
    adj[u].push_back(make_pair(v, weight));
    //adj[v].push_back(u);
}

void printGraph(vector<pair<int, int>> adj[], int V1)
{
    for (int i = 0; i < V; i++)
    {
        cout << "head -> " << i;
        for (int j = 0; j < adj[i].size(); j++)
            cout << " -> " << adj[i][j].first << "," << adj[i][j].second;
        printf("\n");
    }
}

int main()
{
    vector<pair<int, int>> adj[V]; //vector of arrays
    addEdge(adj, 0, 1, 1);
    addEdge(adj, 0, 4, 5);
    addEdge(adj, 1, 1, 2);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 1, 3, 4);
    addEdge(adj, 1, 4, 2);
    addEdge(adj, 3, 2, 2);
    addEdge(adj, 3, 4, 3);
    printGraph(adj, V);
    return 0;
}