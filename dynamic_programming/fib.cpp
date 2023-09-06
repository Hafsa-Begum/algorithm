#include <bits/stdc++.h>
using namespace std;

int fib(int n){
    if(n==0 || n==1){
        return 1;
    }
    int ans1 = fib(n-1);
    int ans2 = fib(n-2);
    return ans1+ans2;
}

int main()
{
    int n; cin>>n;
    cout<<fib(n)<<endl;
    return 0;
}