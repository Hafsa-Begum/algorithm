#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int s; cin>>s;
    int dp[n+1][s+1];
    dp[0][0] = 0;
    for(int j = 1; j<=s; j++){
        dp[0][j] = INT_MAX-1; //1 is minus here to ignore infinity error
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if(a[i-1]<=j){
                dp[i][j] = min(1+dp[i][j-a[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
        
    }
    cout<<dp[n][s]<<endl;
    return 0;
}

/*
coin change 2 is same as the ways to count no of multiple ways to take min coin
input
3
1 2 3
5
output
5
*/