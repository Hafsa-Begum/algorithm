link - 

//using top-up approach
class Solution{
    public:
    int dp[1005][1005];
    int knapsack(int s, int w[], int v[], int n) 
    { 
       // Your code here
       if(n==0 || s==0) return 0;
       if(dp[n][s] != -1) return dp[n][s];
       if(w[n-1]<=s){
           return dp[n][s] = max(v[n-1]+knapsack(s-w[n-1], w, v, n-1), knapsack(s, w, v, n-1));
       }
       else{
           return dp[n][s] = knapsack(s, w, v, n-1);
       }
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int s, int w[], int v[], int n) 
    { 
       // Your code here
       for(int i = 0; i<=n; i++){
           for(int j = 0; j<=s; j++){
               dp[i][j] = -1;
           }
       }
       return knapsack(s, w, v, n);
    }
};

//using loop bottom-up approach
class Solution{
    public:
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int s, int w[], int v[], int n) 
    { 
       // Your code here
       int dp[n+1][s+1];
       for(int i = 0; i<=n; i++){
           for(int j = 0; j<=s; j++){
               if(i==0 || j==0) dp[i][j] = 0;
           }
       }
       for(int i = 1; i<=n; i++){
           for(int j = 1; j<=s; j++){
               if(w[i-1]<=j) dp[i][j] = max(v[i-1]+dp[i-1][j-w[i-1]], dp[i-1][j]);
               else dp[i][j] = dp[i-1][j];
           }
       }
       return dp[n][s];
    }
};