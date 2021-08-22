#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[], int start, int vertices)
{

    bool vis[vertices];
    for (int i = 0; i < vertices; i++)
    {
        vis[i] = false;
    }
    queue<int> q;
    q.push(start);

    cout << sizeof(vis) / sizeof(vis[0]) << endl;
    vis[start] = true;
    while (!q.empty())
    {
        int node = q.front();

        q.pop();
        cout << node << " ";
        vector<int>::iterator it;
        for (it = adj[node].begin(); it != adj[node].end(); it++)
        {
            if (!vis[*it])
            {
                vis[*it] = 1;
                q.push(*it);
            }
        }
    }
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

    bfs(adj, 0, n);
    return 0;
}