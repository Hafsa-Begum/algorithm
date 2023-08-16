#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e3 + 5;
const int INF = 1e9 + 5;
vector<pii> adj[N];
vector<int> dist(N, INF);
vector<bool> visited(N);


void dijkstra(int source){
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    dist[source] = 0;
    pq.push({dist[source], source});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;
        for(pii vpair:adj[u]){
            int v = vpair.first;
            int w = vpair.second;
            if(visited[v]) continue;
            if(dist[v]>dist[u]+w){
                dist[v] = dist[u] + w;
                pq.push({dist[v],v});
            }
        }
    }
    
}

int main()
{
    int n, m; cin>>n>>m;
    for(int i = 0; i<m; i++){
        int u, v, w; cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    dijkstra(1);

    for(int i = 1; i<=n; i++){
        cout<<"Distance of "<<i<<" : ";
        cout<<dist[i]<<endl;
    }
    return 0;
}

/*
SSSP = Single Source Shortest Path
** when there is weight in graph and we need to find shortest distance and shortest path,
it's not possible to get from bfs, in this case dijkstra algorithm help us to get our desired
output.
** dijkstra algorithm works based of priority queue(heap), which prioritize the lowest weight value of every node
** if the weight of every edges is same then bfs works to get shortest distance and path
**limitation of dijkstra is:
can not calculate negative edges value to get shortest distance and path

input-1
7 
8
1 2 3
1 3 5
3 4 1
4 6 1
2 5 6
5 6 1
5 7 2
3 7 12
output-1
Distance of 1 : 0
Distance of 2 : 3
Distance of 3 : 5
Distance of 4 : 6
Distance of 5 : 8
Distance of 6 : 7
Distance of 7 : 10

input-1
7 
8
1 2 3
1 3 5
3 4 1
4 6 1
2 5 4
5 6 1
5 7 2
3 7 1

output-2
Distance of 1 : 0
Distance of 2 : 3
Distance of 3 : 5
Distance of 4 : 6
Distance of 5 : 7
Distance of 6 : 7
Distance of 7 : 6
*/