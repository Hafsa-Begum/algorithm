#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
int visited[N];
int height[N];

void dfs(int u){
    visited[u] = true;
    for(int v:adj[u]){
        if(visited[v]) continue;
        dfs(v);
        height[u] = max(height[v]+1, height[u]);
    }
}

int main()
{
    int n, m; cin>>n>>m;
    for(int i = 0; i<m; i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int num; cin>>num;
    dfs(1);
    cout<<"height of "<<num<<" = "<<height[num]<<endl;
    return 0;
}