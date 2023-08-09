#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector< vector<int> > adj(N);
bool visited[N];
int depth[N];
int height[N];

void dfs(int u){
    visited[u] = true;
    for(int v: adj[u]){
        if(visited[v]) continue;
        depth[v] = depth[u] + 1;
        dfs(v);
        height[u] = max(height[v]+1, height[u]);
    }
    // cout<<u<<" ";
}

int main()
{
    int n, m; cin>>n>>m;
    for(int i = 0; i<m; i++){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    int num; cin>>num;
    cout<<"height of "<<num<<" is "<<height[num]<<endl;
    for(int i = 0; i<n; i++){
        cout<<"depth of "<<i<<" is "<<depth[i]<<endl;
    }

    for(int i = 0; i<n; i++){
        cout<<"height of "<<i<<" is "<<height[i]<<endl;
    }
    return 0;
}