#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
int visited[N];
int level[N];

void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v:adj[u]){
            if(visited[v]) continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
        }
    }
    
}
int main()
{
    int n, m; cin>>n>>m;
    for(int i = 0; i<m; i++){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
  
    int q; cin>>q;
    for(int i = 0; i<q; i++){
        int s, d; cin>>s>>d;
        bfs(s);
        if(visited[d]){
            cout<<level[d]<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
        memset(visited, 0, sizeof(visited));
        memset(level, 0, sizeof(level));
    }
    
    return 0;
}