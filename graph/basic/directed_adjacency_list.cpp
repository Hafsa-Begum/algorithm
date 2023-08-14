#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<vector<int> > adj(N);
const int N1 = 1e3 + 5;
int adjmat[N1][N1];

int main()
{
    int n, m; cin>>n>>m;

    for(int i = 0; i<m; i++){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i = 1; i<=n; i++){
        cout<<"List "<<i<<": ";
        for(int x:adj[i]){
            cout<<x<<" ";
            adjmat[i][x] = 1;
        }
        cout<<endl;
    }
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cout<<adjmat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}