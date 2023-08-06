#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    int arr[n];
    map<int, int> mp;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
        mp[arr[i]]++;
    }
    int k; cin>>k;

    if(mp[k]>1){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}