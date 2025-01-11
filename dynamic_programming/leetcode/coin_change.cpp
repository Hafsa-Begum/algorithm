// link - https://leetcode.com/problems/coin-change/
class Solution {
public:
    int coinChange(vector<int>& a, int s) {
        int n = a.size();
        int dp[n+1][s+1];
        dp[0][0] = 0;
        for(int j = 1; j<=s; j++){
            dp[0][j] = INT_MAX-1;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= s; j++)
            {
                if(a[i-1]<=j){
                    dp[i][j] = min(1+dp[i][j-a[i-1]], dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
            
        }

        return dp[n][s]==INT_MAX-1 ? -1 : dp[n][s];
    }
};