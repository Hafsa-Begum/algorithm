// link - https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution{
     public:
    
    int longestCommonSubstr (string a, string b, int n, int m)
    {
        // your code here
        int dp[n+1][m+1];
        for(int i = 0; i<=n ; i++){
            for(int j = 0; j<=m; j++){
                if(i==0 || j == 0) dp[i][j] = 0;
            }
        }
        for(int i = 1; i<=n ; i++){
            for(int j = 1; j<=m; j++){
                if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else{
                    dp[i][j] = 0;
                }
            }
        }
        int mx = 0;
        
        for(int i = 0; i<=n ; i++){
            for(int j = 0; j<=m; j++){
                if(dp[i][j]>mx) {
                    mx = dp[i][j];
                }
            }
        }
        return mx;
    }
}