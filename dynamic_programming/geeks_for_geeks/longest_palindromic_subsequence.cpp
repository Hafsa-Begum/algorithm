// link - https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution{
    public:
    int longestPalinSubseq(string a) {
        //code here
        int n = a.size();
        string b = a; 
        reverse(b.begin(), b.end());
        int m = b.size();
        int dp[n+1][m+1];
        for(int i = 0; i<=n; i++){
            for(int j = 0; j<=m ; j++){
                if(i==0 || j==0) dp[i][j] = 0;
            }
        }
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m ; j++){
                if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[n][m];
    }
}