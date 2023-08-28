#include <bits/stdc++.h>
using namespace std;
const int INF = 100;
int main()
{
    int n; cin>>n;
    int dist[n+1][n+1];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){  
            if(i==j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>dist[i][j];
            if(dist[i][j]==-1){
                dist[i][j] = INF;
            }
        }
    }
    int mx = INT_MIN;
    for(int k = 0; k<n; k++){
        for(int i = 0; i<n; i++){
           for(int j = 0; j<n; j++){
            if(dist[i][k] != INF && dist[k][j] != INF){
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                mx = max(mx, dist[i][j]);
            }
           } 
        }
    }
    
    cout<<mx<<endl;
    
    return 0;
}