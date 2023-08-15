#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e5 + 10;
const int INF = 1e9 + 10;
vector<pii> g[N];
vector<int> dist(N, INF);
vector<bool> visited(N);
vector<int> parent(N);

void dijkstra(int s){
    priority_queue<pii, vector<pii> , greater<pii> > pq;
    dist[s] = 0;
    pq.push({dist[s], s});
    parent[s] = -1;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;

        for(auto vpair:g[u]){
            int v = vpair.second;
            int w = vpair.first;
            if(visited[v]) continue;
            if(dist[v]>dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
                parent[v] = u;
            }
        }
    }
    
}
int main()
{
    int n,m; cin>>n>>m;
    for(int i = 0; i<m; i++){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({w,v});
    }
    int s, d; cin>>s>>d;
    dijkstra(s);
    cout<<"distance "<<dist[d]<<endl;
    vector<int> path;
    int curr = d;
    while (curr!=-1)
    {
        path.push_back(curr);
        curr = parent[curr];
    }
    reverse(path.begin(), path.end());
    for(int x:path){
        cout<<x<<" ";
    }

    return 0;
}

/*
Question: You will be given a directed weighted graph. At first you will be given N, the number of nodes then you will be given M, the number of edges. The value of nodes are from 1 to N. Next M lines will contain A, B and W which means there is an edge from A to B where the cost is W. There will be no negative weight in the graph.
Also, you will be given a source and a destination. You need to tell the shortest distance between source and destination.
Sample Input
Sample Output
6 9
1 2 5
2 3 2
1 3 10
3 4 1
4 1 5
1 5 9
5 6 1
2 6 4
2 5 2
4 6
13

The shortest path is 4-> 1-> 2-> 5-> 6, so the shortest distance is 13.

*/