#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<int> *adj;

public:
    Graph(int vertices)
    {
        V = vertices;
        adj = new vector<int>[V];
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    bool Qdetectcycle(int start, vector<bool> &vis, vector<bool> &recstack, vector<int> adj[])
    {
        vis[start] = 1;
        recstack[start] = 1;
        for (auto x : adj[start])
        {
            if (!vis[x] && Qdetectcycle(x, vis, recstack, adj))
            {
                return true;
            }
            else if (recstack[x] == 1)
            {
                return true;
            }
        }
        recstack[start] = false;
        return false;
    }
    bool isCyclic(int V)
    {
        vector<bool> visited(V, false);
        vector<bool> recstack(V, false);
        for (int u = 0; u < V; u++)
        {
            if (!visited[u])
            {
                if (Qdetectcycle(u, visited, recstack, adj))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    //g.addEdge(2, 0);
    g.addEdge(2, 3);
    //g.addEdge(3, 3);

    if (g.isCyclic(4))
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}