#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, d; cin>>n>>d;
    int s = 0; int a[n];
    for(int i = 0; i<n; i++){
        cin>>a[i];
        s+=a[i];
    }
    int s1 = (d+s)/2;
    int dp[n+1][s+1];
    dp[0][0] = 1;
    for(int j = 1; j<=s1; j++){
        dp[0][j] = 0;
    }
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<=s1; j++){
            if(a[i-1]<=j){
                dp[i][j] = dp[i-1][j-a[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    cout<<dp[n][s1]<<endl;
    return 0;
}