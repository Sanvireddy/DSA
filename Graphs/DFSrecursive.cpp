#include <bits/stdc++.h>
using namespace std;

void dfs(vector<bool> &visited, vector<int> &v, vector<int> adj[], stack<int> &s)
{
    if (s.empty())
        return;
    int node = s.top();
    s.pop();
    if (!visited[node])
    {
        v.push_back(node);
        visited[node] = 1;
    }
    vector<int>::iterator it;
    for (it = adj[node].begin(); it != adj[node].end(); it++)
    {
        if (!visited[*it])
        {
            s.push(*it);
            dfs(visited, v, adj, s);
        }
    }
    return;
}
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<bool> vis(V, false);
    vector<int> output;
    stack<int> s;
    s.push(0);
    dfs(vis, output, adj, s);
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