// link - https://www.codingninjas.com/studio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
int findWays(vector<int>& a, int s)
{
	// Write your code here.
	const int mod = 1e9+7;
	int n = a.size();
	int dp[n+1][s+1];
	dp[0][0] = 1;
	for(int j = 1; j<=s; j++){
		dp[0][j] = 0;
	}
	for(int i = 1; i<=n; i++){
		for(int j = 0; j<=s; j++){
			if(a[i-1]<=j){
				dp[i][j] = (dp[i-1][j-a[i-1]] + dp[i-1][j])%mod;
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][s];
}
