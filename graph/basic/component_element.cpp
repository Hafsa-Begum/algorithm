#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
int visited[N];

void bfs(int s, int &n){
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        n++;
        for(int v:adj[u]){
            if(visited[v]) continue;
            visited[v] = true;
            q.push(v);
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

    vector<int> v;
    for(int i = 0; i<n; i++){
        int num = 0;
        if(!visited[i]){  
            bfs(i, num);
            v.push_back(num);
        }
    }
    sort(v.begin(), v.end());
    for(int x:v){
        cout<<x<<" ";
    }
    return 0;
}