// link - https://www.codingninjas.com/studio/problems/dijkstra-s-shortest-path_985358

void dij(int s, vector<vector<pair<int, int>> > &g, vector<int> &dist, vector<bool> &visited){
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>> > pq;
    dist[s] = 0;
    pq.push({dist[s], s});
    

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;

        for(pair<int, int> vpair:g[u]){
            int v = vpair.second;
            int w = vpair.first;
            if(visited[v]) continue;
            if(dist[v]>dist[u]+w){
                dist[v] = dist[u]+w;
                pq.push({dist[v], v});
            }
        }
    }

}

vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
{
    // Write your code here.
    // ‘edge’ contains {u, v, distance} vectors.
    vector<vector<pair<int, int>> > g(vertices);
    for(auto e:edge){
        int u = e[0], v = e[1], w = e[2];
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }
    vector<int> dist(vertices, INT_MAX);
    vector<bool> visited(vertices, false);
    dij(source, g, dist, visited);
    
    return dist;
}