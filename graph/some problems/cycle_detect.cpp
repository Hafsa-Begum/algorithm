#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<int> adj[N];
int visited[N];

bool dfs(int u, int p = -1){
    visited[u]=true;
    bool cycleExists = false;
    for(int v:adj[u]){
        if(v == p) continue;
        if(visited[v]) {
            return true;
        }
        cycleExists = cycleExists || dfs(v, u);
    }
    return cycleExists;
}
int main()
{
    int n, m; cin>>n>>m;
    for(int i = 0; i<m; i++){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(dfs(1)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}