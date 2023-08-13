#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
int visited[N];

void dfs(int u){
    visited[u] = true;
    for(int v:adj[u]){
        if(visited[v]) continue;
        dfs(v);
    }
}
void bfs(int s, int component){
    queue<int> q;
    q.push(s);
    visited[s] = true;
    
    cout<<"Components of "<<component<<" : ";
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout<<u<<" ";
        for(int v:adj[u]){
            if(visited[v]) continue;
            q.push(v);
            visited[v] = true;
        }
    }
    
}
int main()
{
    int n, m; cin>>n>>m;
    for(int i = 0; i<m ;i++){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int cc = 0;
    for(int i = 1; i<=n; i++){
        if(visited[i]) continue;
        dfs(i);
        cc++;
    }
    cout<<cc<<endl;
    memset(visited, 0, sizeof(visited));
    int component = 1;
    for(int i = 1; i<=n; i++){
        if(!visited[i]){
            bfs(i, component);
            component++;
            cout<<endl;
        }
    }
    return 0;
}