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

    void DFSutil(int start, vector<bool> &visited)
    {

        stack<int> s;
        s.push(start);

        int node;
        while (!s.empty())
        {
            node = s.top();
            if (!visited[node])
            {
                cout << node << " ";
                visited[node] = 1;
            }
            s.pop();

            for (int i = 0; i < adj[node].size(); i++)
            {
                if (!visited[adj[node][i]])
                {
                    s.push(adj[node][i]);
                }
            }
        }
    }

    void DFS()
    {
        vector<bool> visited(V, false);
        for (int u = 0; u < V; u++)
        {
            if (!visited[u])
            {
                //cout << u << endl;
                DFSutil(u, visited);
            }
        }
    }
};

int main()
{
    // Create a graph given in the above diagram
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(4, 5);
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.DFS();

    return 0;
}