// link - https://www.spoj.com/problems/FARIDA/en/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, caseNum = 1;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        
        if (n == 0)
        {
            cout <<"Case "<<caseNum++<<": "<< 0 << endl;
            continue;
        }
        long long int a[n];
        for (long long int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (n == 1)
        {
            cout<<"Case "<<caseNum++<<": "<< a[0] << endl;
            continue;
        }

        long long int dp[n];
        dp[0] = a[0];
        dp[1] = max(a[0], a[1]);

        for (long long int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
        }
        cout<<"Case "<<caseNum++<<": " << dp[n - 1] << endl;
    }

    return 0;
}