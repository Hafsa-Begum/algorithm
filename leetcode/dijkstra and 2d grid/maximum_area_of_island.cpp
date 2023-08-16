// link - https://leetcode.com/problems/max-area-of-island/

class Solution {
public:
    static const int N = 60;
    bool visited[N][N];
    void dfs(int i, int j, vector<vector<int>>& g, int &n){
        if(i<0 || i>=g.size() || j<0 || j>=g[0].size()) return;
        if(g[i][j] == 0) return;
        if(visited[i][j]) return;
        visited[i][j] = true;
        n++;
        dfs(i, j-1, g, n);
        dfs(i, j+1, g, n);
        dfs(i-1, j, g, n);
        dfs(i+1, j, g, n);
    }
    int maxAreaOfIsland(vector<vector<int>>& g) {
        int m = g.size();
        if(m == 0) return 0;
        int n = g[0].size();
        vector<int> v;
        for(int i = 0; i<m ; i++){
            for(int j = 0; j<n ; j++){
                if(g[i][j] != 0 && !visited[i][j]){
                int n = 0;
                dfs(i,j,g,n);
                v.push_back(n);
                    
                }
                
            }
        }
        if(v.size()==0) return 0;
        sort(v.begin(), v.end(), greater());
        return v[0];
    }
};