// link - https://leetcode.com/problems/target-sum/
class Solution {
public:
    int findTargetSumWays(vector<int>& a, int t) {
        int n = a.size();
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum+=a[i];
        }
        
        if((t+sum) % 2 == 1 || sum<abs(t)){
            return 0;
        }
        else{
            int s = (t+sum)/2;
            int dp[n+1][s+1];
            dp[0][0] = 1;
            for(int j = 1; j<=s; j++){
                dp[0][j] = 0;
            }
            for(int i = 1; i<=n; i++){
                for(int j = 0; j<=s; j++){
                    if(a[i-1]<=j){
                        dp[i][j] = dp[i-1][j-a[i-1]] + dp[i-1][j];
                    }
                    else{
                    dp[i][j] = dp[i-1][j]; 
                    }
                }
            }
            return dp[n][s];
            
        }
    }
};