#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> g[N];
bool visited[N];
int level[N];
int parent[N];

void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v:g[u]){
            if(visited[v]) continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
            parent[v] = u;
        }
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
    bfs(1);
    if(!visited[n]){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    vector<int> path;
    int current = n;
    while (current != -1)
    {
        path.push_back(current);
        current = parent[current];
    }
    reverse(path.begin(), path.end());
    int sz = path.size();
    cout<<sz<<endl;
    for(int c:path){
        cout<<c<<" ";
    }
    return 0;
}