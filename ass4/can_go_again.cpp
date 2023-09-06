#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e7+7;
const int INF = 1e9+7;
vector<pii> g[N];
vector<int> d(N,INF);
int n, m;
bool negCycle = false;
void bellman_ford(int s){
    d[s] = 0;
    for(int i = 1; i<=n; i++){
        //all edges relaxation
        for(int u = 1; u<=n; u++){
            for(pii vpair:g[u]){
                int v = vpair.first;
                int w = vpair.second;
                if(d[u] != INF && d[v]>d[u]+w){
                    d[v] = d[u] + w;
                }
            }
        }
    }
    
    //all edges relaxation
    for(int u = 1; u<=n; u++){
        for(pii vpair:g[u]){
            int v = vpair.first;
            int w = vpair.second;
            if(d[u] != INF && d[v]>d[u]+w){
                negCycle = true;
                break;
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
    }
    int s; cin>>s;
    bellman_ford(s);
    if(negCycle){
        cout<<"Negative Cycle Detected"<<endl;
    }
    else{
        int t; cin>>t;
        while (t--)
        {
            int x; cin>>x;
            
            if(d[x] != INF){
                cout<<dist[x]<<endl;
            }
            else{
                cout<<"Not Possible"<<endl;
            }
        }
    }
    
    return 0;
}