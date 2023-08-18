// link - https://leetcode.com/problems/as-far-from-land-as-possible/

class Solution {
public:
    int maxDistance(vector<vector<int>>& g) {
        vector<pair<int, int> > direc = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        queue<pair<int, int> > q;
        int n = g.size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(g[i][j]==1){
                    q.push({i, j});
                }
            }
        }
        if(q.empty() || q.size() == n*n){
            return -1;
        }
        int dist = -1;
        while(!q.empty()){
            int sz = q.size();
            for(int k = 0; k<sz; k++){
                pair<int, int> upair = q.front();
                q.pop();
                int i = upair.first;
                int j = upair.second;
                for(pair<int, int> d:direc){
                    int ni = i + d.first;
                    int nj = j + d.second;
                    if(ni<0 || ni>=n || nj<0 || nj>=n || g[ni][nj] != 0){
                        continue;
                    }
                    g[ni][nj] = 1;
                    q.push({ni, nj});
                }
            }
            cout<<dist<<" ";
            dist++;
        }
        return dist;
    }
};