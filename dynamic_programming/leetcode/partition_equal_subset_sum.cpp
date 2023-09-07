// link - https://leetcode.com/problems/partition-equal-subset-sum/
class Solution {
public:
    bool canPartition(vector<int>& a) {
        int n = a.size();
        int s = 0;
        for(int i = 0; i<n; i++){
            s+=a[i];
        }

        if(s%2==0){
            int s1 = s/2;
            bool dp[n+1][s1+1];
            dp[0][0] = true;
            for(int j = 1; j<=s1; j++){
                dp[0][j] = false;
            }
            for(int i = 1; i<=n; i++){
                for(int j = 0; j<=s1; j++){
                    if(a[i-1]<=j){
                        dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];
                    }
                    else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
            return dp[n][s1];
        }
        else{
            return false;
        }
    }
};