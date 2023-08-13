#include <bits/stdc++.h>
using namespace std;

const int N = 20 + 5;
vector<int> adj[N];
int visited[N];

void dfs(int u, int p, vector<int> &a ){
    visited[u] = true;
        for(int v:adj[u]){
        if(visited[v]) continue;
        if(u == p) a.push_back(v);
        dfs(v, u, a);
    
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
    int p; cin>>p;
    vector<int> v;
    dfs(0 ,p, v);
    
    cout<<v.size()<<" ";
    
    return 0;
}