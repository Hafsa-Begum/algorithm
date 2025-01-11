// link - https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
class Solution{
    public:
    int dp[1005][1005];
    
    Solution(){
        for(int i = 0; i<1005; i++){
        for(int j = 0; j<1005; j++){
            dp[i][j] = -1;
        }
    }
    }
    
    int knapSack(int n, int s, int v[], int w[])
    {
        // code here
        if(n==0 || s== 0) return 0;
        if(dp[n][s] != -1){
            return dp[n][s];
        }
        if(w[n-1]<=s){
            int ch1 = v[n-1] + knapSack(n, s-w[n-1], v, w);
            int ch2 = knapSack(n-1, s, v, w);
            return dp[n][s] = max(ch1, ch2);
            
        }
        else{
            return dp[n][s] = knapSack(n-1, s, v, w);
        }
    }
}