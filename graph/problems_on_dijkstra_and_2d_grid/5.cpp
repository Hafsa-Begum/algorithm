#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e3+5;
vector<string> g;
bool visited[N][N];
int level[N][N];
pii parent[N][N];
vector<pii> direc = {{0, -1},{0, 1},{-1, 0},{1, 0}};
int n, m; 
bool isValid(int i, int j){
    return (i>=0 && i<n && j>=0 && j<m);
}
void bfs(int si, int sj){
    queue<pii> q;
    q.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty())
    {
        pii upair = q.front();
        q.pop();

        int i = upair.first;
        int j = upair.second;

        for(pii d:direc){
            int ni = i+d.first;
            int nj = j+d.second;
            if(isValid(ni,nj) && !visited[ni][nj] && g[ni][nj]!='x'){
                q.push({ni, nj});
                visited[ni][nj] = true;
                level[ni][nj]=level[i][j] + 1;
                parent[ni][nj] = {i,j};
            }
        }
    }
    
}
int main()
{
    cin>>n>>m;
    int si, sj, di, dj;
    for(int i = 0; i<n; i++){
        string x; cin>>x;
        for(int j = 0; j<m; j++){
            if(x[j] == 's'){
                si = i;
                sj = j;
            }
            if(x[j] == 'e'){
                di = i;
                dj = j;
            }
        }
        g.push_back(x);
    }
    
    bfs(si,sj);
    if(level[di][dj] != 0){
        cout<<level[di][dj]<<endl;
    }
    else{
       cout<<"-1"<<endl; 
    }
    vector<pii> path;
    pii cur = {di, dj};

    while (!(cur.first == si && cur.second == sj)){
        path.push_back(cur);
        cur = parent[cur.first][cur.second];
    }
    path.push_back({si,sj});
    reverse(path.begin(), path.end());
    for(int i = 1; i<path.size(); i++){
        if(path[i-1].first == path[i].first){
            if(path[i-1].second == path[i].second-1){
                cout<<"R";
            }
            else{
                cout<<"L";
            }
        }
        else{
            if(path[i-1].first == path[i].first-1){
                cout<<"D";
            }
            else{
                cout<<"U";
            }
        }
    }
    return 0;
}

/*
Question: You are given a 2D grid which will contain only the characters ‘s’, ‘.’, ‘x’ and ‘e’. The size of the grid is N*M squares, where ‘s’ means where you should start, ‘.’ means there is a path, ‘x’ means there is no path and ‘e’ means where you should stop. You can walk left, right, up, and down through the cell of squares. You need to tell the minimum number of steps you need to go from ‘S’ to ‘E’. There will be exactly one ‘s’ and one ‘e’. If there is no path, print -1.

Sample Input
Sample Output
6 5
.s.x.
...x.
..x..
..x..
..xex
.....
8
5 5
.s.x.
...x.
..x..
..x..
..xex
-1
5 5
.....
.....
.x..e
s.x..
....x
7



*/

/*
Question: You are given a 2D grid which will contain only the characters
‘s’, ‘.’, ‘x’ and ‘e’. The size of the grid is N*M squares, where ‘s’ means
where you should start, ‘.’ means there is a path, ‘x’ means there is no
path and ‘e’ means where you should stop. You can walk left, right, up,
and down through the cell of squares. You need to tell the minimum number
of steps you need to go from ‘S’ to ‘E’ and also you need to print the path
in the form of R(Right), L(Left), U(Up) and D(Down) from source to destination. 
There will be exactly one ‘s’ and one ‘e’. If there is no path, print -1.
Sample Input
6 5
.s.x.
...x.
..x..
..x..
..xex
.....
Sample Output
8
DDDDDRRU
Sample Input
5 5
.s.x.
...x.
..x..
..x..
..xex
Sample Output
-1
Sample Input
5 5
.....
.....
.x..e
s.x..
....x
Sample Output
7
UURRRRD
or
7
RDRRURU
*/