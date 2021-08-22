#include<bits/stdc++.h>
using namespace std;

void addVertex(vector<vector<int>> &adj,int u,int v)
{
    adj[u].push_back(v);
}

void bfs(int i, vector<vector<int>>& adj,int V)
{
    cout << i << " ";
    vector<bool> visited(V,false);
    visited[i] =1;
    queue<int> q;
    q.push(i);
    int u;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(int j=0;j<adj[u].size();j++)
        {
            if(!visited[adj[u][j]])
            {
                visited[j]=1; q.push(adj[u][j]);
                cout << adj[u][j] << " ";
            }
        }
    }
}

int main()
{
    int V=6;
    
    vector<vector<int>> adj(V);
    addVertex(adj,0,1);
    addVertex(adj,0,2);
    addVertex(adj,0,3);
    addVertex(adj,1,1);
    addVertex(adj,2,1);
    addVertex(adj,3,1);
    addVertex(adj,3,2);
    addVertex(adj,3,4);
    addVertex(adj,4,5);
    bfs(0,adj,V);
    

    vector<string> s = {"9","34","3","2","5","30"};
    sort(s.begin(),s.end());
    for(int i=0;i<s.size();i++)
    cout << s[i] << " ";
    int i = 1;
    cout << !i << endl;
    return 0;
}
