#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e7+7;
const int INF = 1e9+7;
vector<pii> g[N];
vector<pair<pii, int> > list_of_edges;
vector<int> d(N,INF);
int n, m;
void bellman_ford(int s){
    d[s] = 0;
    for(int i = 1; i<=n; i++){
        //all edges relaxation
        // for(int u = 1; u<=n; u++){
        //     for(pii vpair:g[u]){
        //         int v = vpair.first;
        //         int w = vpair.second;
        //         if(d[u] != INF && d[v]>d[u]+w){
        //             d[v] = d[u] + w;
        //         }
        //     }
        // }

        for(auto edge:list_of_edges){
            int u = edge.first.first;
            int v = edge.first.second;
            int w = edge.second;
            if(d[u]!=INF && d[v]>d[u]+w){
                d[v] = d[u]+w;
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    while (m--)
    {
        int u, v, w; cin>>u>>v>>w;
        g[u].push_back({v,w});
        list_of_edges.push_back({{u,v},w});
    }
    bellman_ford(1);
    for(int i = 1; i<=n; i++){
        cout<<"Distance of "<<i;
        cout<<": "<<d[i]<<endl;
    }
    return 0;
}

/*
every edge will be relaxed for (n-1) times
time complexity: 
O(|E| |v-1|)
O(nm)
sparse graph - O(n^2)
complete graph- if there present all edges - O(n^3)
bellman ford can not find shortest path in negative weighted cycle graph
rather it helps to detect negative weighted cycle
**it is called bottom-up approach

7
10
1 2 6
1 3 5
1 4 5
2 5 -1
3 2 -2
3 5 1
4 3 -2
4 6 -1
5 7 3
4 7 3
output
Distance of 1: 0
Distance of 2: 1
Distance of 3: 3
Distance of 4: 5
Distance of 5: 0
Distance of 6: 4
Distance of 7: 3

input
4
4
1 2 4
1 3 3
3 4 5
4 2 -10

output
Distance of 1: 0
Distance of 2: -2
Distance of 3: 3
Distance of 4: 8
*/