#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+9;
vector<int> dp(N, INT_MAX);
int solve(int n){
    //base case
    if(n==0) return 0;
    if(dp[n]!=INT_MAX) return dp[n];
    vector<int> digit;
    for(char ch:to_string(n)){
        digit.push_back(ch-'0');
    }
    //digit extract
    for(int d:digit){
        dp[n] = min(dp[n], solve(n-d)+1);
    }
    return dp[n];
}
int main()
{
    int n; cin>>n;
    cout<<solve(n);
    
    return 0;
}