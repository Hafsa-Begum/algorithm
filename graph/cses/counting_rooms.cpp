#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e3 + 10;
vector<string> g;
bool visited[N][N];
vector<pii> direc = {{0,-1},{0,1},{-1,0},{1,0}};
int n, m;

bool isValid(int i, int j){
    return (i>=0 && i<n && j>=0 && j<m);
}

void dfs(int i, int j){
    if(!isValid(i,j)) return;
    if(visited[i][j]) return;
    if(g[i][j] == '#') return;
    visited[i][j] = true;
    for(auto d:direc){
        dfs(i+d.first, j+d.second);
    }
}

int main()
{
    cin>>n>>m;
    for(int i =0; i<n; i++){
        string s; cin>>s;
        g.push_back(s);
    }
    int ct = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(g[i][j] == '#') continue;
            if(visited[i][j]) continue;
            dfs(i,j);
            ct++;
        }
    }
    cout<<ct<<endl;
    return 0;
}

/*
for(auto d:direc){
    dfs(i+d.first, j+d.second);
}
// dfs(i, j-1);
// dfs(i, j+1);
// dfs(i-1, j);
// dfs(i+1, j);


input-1
5 8
########
#..#...#
####.#.#
#..#...#
########
output-1
3
*/