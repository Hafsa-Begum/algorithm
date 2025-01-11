// link - https://practice.geeksforgeeks.org/problems/coin-change2448/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution{
    public:
    long long int count(int a[], int n, int s) {

        // code here.
        long long int dp[n+1][s+1];
        dp[0][0] = 1;
        for(long long int j = 1; j<=s; j++){
            dp[0][j] = 0;
        }
        for (long long int i = 1; i <= n; i++)
        {
            for (long long int j = 0; j <= s; j++)
            {
                if(a[i-1]<=j){
                    dp[i][j] = dp[i][j-a[i-1]] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
            
        }
        return dp[n][s];
    }
}