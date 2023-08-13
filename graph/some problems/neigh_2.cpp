#include <bits/stdc++.h>
using namespace std;

const int N = 20 + 5;
vector<int> adj[N];
int visited[N];

void dfs(int u, int &num){
    visited[u] = true;
        num++;
        for(int v:adj[u]){
        if(visited[v]) continue;
        dfs(v, u, a);
    
    }
}

int main()
{
    int n, m; cin>>n>>m;
    for(int i = 0; i<m; i++){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
    }
    int p; cin>>p;
    int num = 0;
    dfs(p, num);
    
    cout<<num<<endl;
    
    return 0;
}