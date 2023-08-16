// link - https://leetcode.com/problems/flood-fill/

class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &g, int color, int old){
        if(i<0 || i>=g.size() || j<0 || j>=g[0].size()) return;
        if(g[i][j] != old) return;
        
        g[i][j] = color; 
        dfs(i,j-1,g,color, old);
        dfs(i,j+1,g,color, old);
        dfs(i-1,j,g,color, old);
        dfs(i+1,j,g,color, old);
    } 
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        if(oldColor == color) return image;
        dfs(sr, sc, image, color, oldColor);
        return image;
    }
};