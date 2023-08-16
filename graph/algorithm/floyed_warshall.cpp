#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
const int INF = 1e9+10;
int g[N][N];
void print_matrix(int n){
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(g[i][j]==INF) cout<<"x"<<" ";
            else cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
}
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
    print_matrix(n);
    for(int k = 1; k<=n; k++){
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(g[i][k] != INF && g[k][j] != INF)
                    g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
            }
        }
    }
    cout<<"After Floyd Warshall"<<endl;
    print_matrix(n);
    return 0;
}

/*
APSP = All Pair Shortest Path
find shortest path from all nodes to others nodes

5
7
1 2 2
1 3 6
2 3 1
3 4 4
4 2 6
2 5 3
5 4 9

*/