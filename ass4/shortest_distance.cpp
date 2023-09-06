#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
const int INF = 1e9+10;
int g[N][N];

void dist_init(int n){
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(i==j) g[i][j] = 0;
            else g[i][j] = INF;
        }
    }
}
int main()
{
    int n, m; cin>>n>>m;
    dist_init(n);
    for(int i = 0; i<m ; i++){
        int u, v, w; cin>>u>>v>>w;
        g[u][v] = w;
    }

    for(int k = 1; k<=n; k++){
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(g[i][k] != INF && g[k][j] != INF)
                    g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
            }
        }
    }
    cout<<"After Floyd Warshall"<<endl;
    int q; cin>>q;
    while (q--)
    {
        int x, y; cin>>x>>y;
        
        if(dist[x][y] != INF){
            cout<<dist[x][y]<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
    }
    return 0;
}
