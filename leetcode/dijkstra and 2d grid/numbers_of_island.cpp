link - https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    static const int N = 310;
    bool visited[N][N];

    void dfs(int i, int j, vector<vector<char>>& g){
        if(i<0 || i>=g.size() || j<0 || j>=g[0].size()) return;
        if(visited[i][j]) return;
        if(g[i][j] == '0') return;
        visited[i][j] = true;
        dfs(i, j-1, g);
        dfs(i, j+1, g);
        dfs(i-1, j, g);
        dfs(i+1, j, g);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m==0) return 0;
        int n = grid[0].size();
        int il = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == '0') continue;
                if(visited[i][j]) continue;
                dfs(i,j, grid);
                il++;
            }
        }
        return il;
    }
};