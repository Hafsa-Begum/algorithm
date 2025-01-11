class Solution{
    public:
	int minOperations(string a, string b) 
	{ 
	    // Your code goes here
	    int n = a.size();
        int m = b.size();
        int dp[n+1][m+1];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if(i==0 || j==0) dp[i][j] = 0;
            }  
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }  
        }
        return a.size()-dp[n][m]+b.size()-dp[n][m];
	}
}