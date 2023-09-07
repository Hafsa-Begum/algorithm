// link- https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

class Solution{
    public:
	int minDifference(int a[], int n)  { 
	    // Your code goes here
	    int s = 0;
	    for(int i = 0; i<n; i++){
	        s += a[i];
	    }
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
	    vector<int> v;
	    for(int i = 0; i<=n; i++){
	        for(int j=0; j<=s; j++){
	            if(dp[i][j] != 0){
	                v.push_back(j);
	            }
	        }
	    }
	    int ans = INT_MAX;
	    for(int val:v){
	        int s1 = val;
	        int s2 = s-s1;
	        ans = min(ans, abs(s1-s2));
	    }
	    return ans;
	}
};