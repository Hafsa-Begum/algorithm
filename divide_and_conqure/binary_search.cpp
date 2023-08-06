#include <bits/stdc++.h>
using namespace std;

int search(int nums[], int n, int target) {
    int l = 0;
    int r = n-1;

    while(l<=r){
        int mid = (l+r)/2;
        if(nums[mid] == target){
            return mid; 
        }
        else if(nums[mid]>target){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int n; cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int k; cin>>k;

    int val = search(arr, n, k);

    if(val == -1){
        cout<<"Not Found"<<endl;
    }
    else{
        cout<<val<<endl;
    }
    return 0;
}