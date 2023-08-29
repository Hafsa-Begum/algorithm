#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9+5;
int main()
{
    int n; cin>>n;
    int dist[n][n];
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>dist[i][j];
        }
    }
    
    for(int k = 0; k<n; k++){
        for(int i = 0; i<n; i++){
           for(int j = 0; j<n; j++){
            if(dist[i][k] != INF && dist[k][j] != INF){
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
           } 
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){  
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}