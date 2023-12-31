#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<int> adj[N];
int visited[N];
int depth[N];

void dfs(int u){
    visited[u] = true;
    
    for(int v:adj[u]){
        if(visited[v]) continue;
        depth[v] = depth[u] + 1;
        dfs(v);
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
    int num; cin>>num;
    dfs(1);
    cout<<"depth of "<<num<<" = "<<depth[num]<<endl;
    return 0;
}