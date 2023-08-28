#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1005;
bool visited[N][N];
int dist[N][N];
char g[N][N];
vector<pii> dir = {{0,-1},{0, 1},{-1, 0},{1, 0}};
int n, m;

bool isValid(int i, int j){
    return (i>=0 && i<n && j>=0 && j<m && g[i][j]=='.');
}
void bfs(int i, int j, int &cnt){
    queue<pii> q;
    q.push({i, j});
    visited[i][j] = true;
    cnt++;
    while (!q.empty())
    {
        pii f = q.front();
        q.pop();
        int pi = f.first;
        int pj = f.second;
        for(auto d:dir){
            int ci = pi + d.first;
            int cj = pj + d.second;
            if(isValid(ci, cj) && !visited[ci][cj]){
                q.push({ci, cj});
                cnt++;
                visited[ci][cj] = true;
                g[ci][cj] = '-';
            }
        }
    }
    
}
int main()
{
    cin>>n>>m;
    for(int i = 0; i<n ; i++){
        for(int j = 0; j<m; j++){
            cin>>g[i][j]; 
        }
    }
    int si, sj; cin>>si>>sj;
    bfs(si, sj);
    int di, dj; cin>>di>>dj;
    if(visited[di][dj]){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
    return 0;
}