#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e5 + 10;
bool visited[N][N];
int level[N][N];
int n, m;
vector<pii> direc = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};
bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
void bfs(int si, int sj)
{
    queue<pii> q;
    q.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty())
    {
        pii upair = q.front();
        int i = upair.first;
        int j = upair.second;
        q.pop();

        for (auto d : direc)
        {
            int ni = i + d.first;
            int nj = j + d.second;
            if (isValid(ni, nj) && !visited[ni][nj])
            {
                q.push({ni, nj});
                visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
            }
        }
    }
}

void reset_level_vis()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            level[i][j] = 0;
            visited[i][j] = false;
        }
    }
}

int main()
{
    cin >> n >> m;
    int si, sj, di, dj;
    cin >> si >> sj >> di>> dj;
    bfs(si, sj);
    if (level[di][dj] != 0)
    {
        cout << level[di][dj] << endl;
    }
    else
        cout << "-1" << endl;
    reset_level_vis();

    return 0;
}

// for(int i = 0; i<n; i++){
//         for(int j = 0; j<m; j++){
//             int si, di, sj, dj;
//             cin>>si>>di>>sj>>dj;
//             bfs(si, sj);
//             if(level[di][dj]==0){
//                 cout<<"-1"<<endl;
//             }
//             else cout<<level[di][dj]<<endl;
//             reset_level_vis();
//         }
//     }