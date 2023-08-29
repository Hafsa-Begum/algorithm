#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9+7;
int main()
{
    int n; cin>>n;
    int dist[n][n];
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>dist[i][j];
            if(dist[i][j]==-1){
                dist[i][j] = INF;
            }
        }
    }
   
    for(int k = 0; k<n; k++){
        for(int i = 0; i<n; i++){
           for(int j = 0; j<n; j++){
            if(dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j]<dist[i][j]){
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                
            }
           } 
        }
    }
    
    int mx = INT_MIN;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(dist[i][j] != INF) {
                mx = max(mx, dist[i][j]);
            }
        }
    }

    cout<<mx<<endl;
    
    return 0;
}