#include <bits/stdc++.h>
using namespace std;
void init_code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif //ONLINE_JUDGE
}

const int N = 1e3 + 5;
vector<int> adj[N];
int visited[N];
int level[N];
void dfs2(int u){
    visited[u] = true;
    for(int v:adj[v]){
        if(visited[v]) continue;
        dfs(v);
    }
}
void bfs2(int s){
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

void bfs(int s){
    queue<int> q;
    level[s] = 0;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        //pop a node from queue and insert 
        //unvisited neighbours of that node
        int u = q.front();
        q.pop();
        //section 1: a node being processed here
        cout<<u<<" ";
        for(int v:adj[u]){
            //section 2: child being processed
            if(visited[v]) continue;
            q.push(v);
            visited[v] = true;
            //section 3: child being processed
            level[v] = level[u] + 1;
        }

    }
    

}

bool dfs(int u, int p = -1){
    bool cycleExists = false;
    visited[u] = true;
    for(int v:adj[u]){
        if(v == p) continue;
        if(visited[v]) return true;
        cycleExists = cycleExists || dfs(v,u);
    }
    return cycleExists;
}
int main()
{
    init_code();
    int n, m; cin>>n>>m;
    for(int i = 0; i<m; i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int f, d; cin>>f>>d;
    bfs(f);
    
    for(int i = 1; i<=n; i++){
        if(i == f)
        cout<<"level of "<<d<<" is "<<level[d]<<endl;
    }
    return 0;
}