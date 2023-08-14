#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> g[N];
bool visited[N];

void dfs(int u){
    visited[u] = true;
    for(int v:g[u]){
        if(visited[v]) continue;
        dfs(v);
    }
}

int main()
{
    int n, m; cin>>n>>m;
    for(int i = 0; i<m; i++){
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> nodes;
    for(int i = 1; i<=n; i++){
        if(visited[i]) continue;
        dfs(i);
        nodes.push_back(i);
    }
    int sz = nodes.size();
    cout<<sz-1<<endl;
    for(int i = 1; i<sz; i++){
        cout<<nodes[i-1]<<" "<<nodes[i]<<endl;
    }
    return 0;
}