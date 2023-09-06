// link - https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/W

#include <bits/stdc++.h>
using namespace std;
bool solve(long long curr, long long n){
    if(curr == n){
        return true;
    }

    if(curr>n){
        return false;
    }

    return solve(curr*10, n) || solve(curr*20, n);
}
int main()
{
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        if(solve(1, n)) {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}