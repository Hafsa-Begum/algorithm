#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;
vector<int> adj[N];
int visited[N];
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
        for(int v:adj[u]){
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
    for(int i = 0; i<m ; i++){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int s, d; cin>>s>>d;
    bfs(s); //O(n+m)
    cout<<"Distance : "<<level[d]<<endl;

    for (int i = 1; i <= n; i++)
    {
        cout<<"Parent of "<<i<<" : "<<parent[i]<<endl;
    }
    //path finding O(n)
    vector<int> path;
    int current = d;
    while (current != -1)
    {
        path.push_back(current);
        current = parent[current];
    }
    reverse(path.begin(), path.end());
    cout<<"Path : ";
    for(int node:path){
        cout<<node<<" ";
    }
    return 0;
}
/*
input-1
7
7
1 2
1 3
3 4
2 5
4 6
6 5
5 7
1 
7
output-1
3
Parent of 1 : -1
Parent of 2 : 1
Parent of 3 : 1
Parent of 4 : 3
Parent of 5 : 2
Parent of 6 : 5
Parent of 7 : 5
Path : 1 2 5 7 

input-2
7
8
1 2
1 3
3 4
2 5
4 6
6 5
5 7
3 7
1 
7
output-2
Distance : 2
Parent of 1 : -1
Parent of 2 : 1
Parent of 3 : 1
Parent of 4 : 3
Parent of 5 : 2
Parent of 6 : 5
Parent of 7 : 3
Path : 1 3 7 

shortest distance from any source to destination is 
the level of that destination from that source

shortest path is the path where nodes crossed from source to destination
to reach that destination
example: from input-2: 1->3>7

*/