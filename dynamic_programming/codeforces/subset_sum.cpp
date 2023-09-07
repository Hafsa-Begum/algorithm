// link - https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution{
    public:
    bool isSubsetSum(vector<int>a, int s){
        // code here 
        int n = a.size();
        bool dp[n+1][s+1];
        dp[0][0] = true;
        for(int j = 1; j<=s; j++){
            dp[0][j] = false;
        }
        for(int i = 1; i<=n; i++){
            for(int j = 0; j<=s; j++){
                if(a[i-1]<=s){
                    dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][s];
    }
};