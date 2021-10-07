#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<bool> &visited, vector<int> &v, vector<int> adj[])
{
    visited[node] = true;
    v.push_back(node);
    vector<int>::iterator it;
    for (it = adj[node].begin(); it != adj[node].end(); it++)
    {
        if (!visited[*it])
        {
            dfs(*it, visited, v, adj);
        }
    }
    return;
}
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<bool> vis(V, false);
    vector<int> output;

    dfs(0, vis, output, adj);
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
    v = dfsOfGraph(n, adj);
    for (auto x : v)
        cout << x << " ";
    return 0;
}