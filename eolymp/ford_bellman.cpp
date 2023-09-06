#include <bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int u;
    int v;
    int w;
    Edge(int u, int v, int w){
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

const int N = 1009;
const int INF = 30000;
vector<int> dist(N, INF);
vector<Edge> g;
int n, m; 
void ford_bellman(int s){
    dist[s] = 0;
    for (int i = 1; i <= n-1; i++)
    {
        for(int j = 0; j<g.size(); j++){
            Edge ed = g[j];
            int u = ed.u;
            int v = ed.v;
            int w = ed.w;
            if(dist[u]!=INF && dist[u]+w<dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }
    
}
int main()
{
    cin>>n>>m;
    for(int i = 0; i<m; i++){
        int u, v, w; cin>>u>>v>>w;
        Edge ed(u, v, w);
        g.push_back(ed);
    }
    ford_bellman(1);
    int mn = INT_MAX;
    for(int i = 1; i<=n; i++){
        if(ci)
        cout<<dist[i]<<" ";
    }
    return 0;
}