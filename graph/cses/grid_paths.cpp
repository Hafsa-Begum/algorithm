#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e3+5;
vector<string> g;
bool visited[N][N];
int level[N][N];
pii parent[N][N];
vector<pii> direc = {{0, 1},{1, 0}};
int n; 
bool isValid(int i, int j){
    return (i>=0 && i<n && j>=0 && j<n);
}
void dfs(int si, int sj){
    if(!isValid(si, sj)) return;
    if(visited[si][sj]) return;
    if(g[si][sj] == 'x') return;
    visited[si][sj] = true;
    for(auto d:direc){
        dfs(si+d.first, sj+d.second);
    }
}

int main()
{
    cin>>n;
    for(int i = 0; i<n; i++){
        string x; cin>>x;
        g.push_back(x);
    }
    int ct = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(g[i][j] =='*') continue;
            if(visited[i][j]) continue;
            dfs(i,j);
            ct++;
        }
    }
    cout<<ct<<endl;
    return 0;
}