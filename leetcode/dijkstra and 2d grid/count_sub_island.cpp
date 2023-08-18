// link - https://leetcode.com/problems/count-sub-islands/

class Solution {
public:
    static const int N = 510;
    int visited[N][N];
    bool dfs(int i, int j, int m, int n, vector<vector<int>>& g1, vector<vector<int>>& g2){
        if(i<0 || i>=m || j<0 || j>=n || visited[i][j] || g2[i][j] == 0) return true; 
        if(g1[i][j] == 0) return false;
        
            visited[i][j] = true;
           bool left = dfs(i,j-1, m, n, g1, g2);
           bool right = dfs(i,j+1, m, n, g1, g2);
           bool up = dfs(i-1,j, m, n, g1, g2);
           bool down = dfs(i+1,j, m, n, g1, g2);

           return left && right && up && down;
           
    }
    int countSubIslands(vector<vector<int>>& g1, vector<vector<int>>& g2) {
        int m = g1.size();
        if(m==0) return 0;
        int n = g1[0].size();

        int cc = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n ; j++){
                if(g2[i][j] == 0 || visited[i][j] || g1[i][j] == 0) continue;
                
                if(dfs(i, j, m, n, g1, g2)) {
                    
                    cc++;
                }
                
            }
        }
        return cc;
    }
};