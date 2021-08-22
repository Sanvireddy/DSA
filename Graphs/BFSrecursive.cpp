#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[], vector<bool> &visited, vector<int> &v, queue<int> &q)
{
    if (q.empty())
        return;

    vector<int>::iterator it;

    int node = q.front();
    q.pop();
    if (!visited[node])
    {
        visited[node] = 1;
        v.push_back(node);
    }
    for (it = adj[node].begin(); it != adj[node].end(); it++)
    {
        if (!visited[*it])
        {

            q.push(*it);
        }
    }
    bfs(adj, visited, v, q);
    return;
}

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<bool> vis(V, 0);
    vector<int> output;
    queue<int> q;
    q.push(0);
    bfs(adj, vis, output, q);
    return output;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        //cout << adj[x][y] << " ";
    }
    vector<int> v;
    v = bfsOfGraph(n, adj);
    for (auto x : v)
        cout << x << " ";
    return 0;
}