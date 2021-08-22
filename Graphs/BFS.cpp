#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph
{
private:
    int V;
    list<int> *adj;

public:
    Graph(int V)
    {
        V = V;
        adj = new list<int>[V];
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    void BFS(int start, vector<bool> &visited)
    {
        //int V = adj[0].size();

        queue<int> q;
        q.push(start);
        list<int>::iterator i;
        while (!q.empty())
        {
            int u = q.front();
            if (!visited[u])
            {
                cout << u << " ";
                visited[u] = 1;
            }
            q.pop();
            for (i = adj[u].begin(); i != adj[u].end(); ++i)
            {
                if (!visited[*i])
                {
                    q.push(*i);
                }
            }
        }
    }

    void TotalBFS()
    {
        vector<bool> visited(V, false);
        for (int u = 0; u < V; u++)
        {
            if (!visited[u])
                BFS(u, visited);
        }
    }
    void printGraph()
    {
        list<int>::iterator j;
        for (int i = 0; i < V; i++)
        {
            for (j = adj[i].begin(); j != adj[i].end(); ++j)
                cout << *j << " ";
            cout << endl;
        }
    }
};

int main()
{
    // Create a graph given in the above diagram
    Graph g(5);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(3, 4);
    g.addEdge(2, 3);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.TotalBFS();

    return 0;
}