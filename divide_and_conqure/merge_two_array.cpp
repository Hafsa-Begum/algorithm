#include <bits/stdc++.h>
using namespace std;

void merge(int arr1[], int n, int arr2[], int m, int result[]){
    int x = 0, y=0, k = 0;

    while(x<n && y<m){
        if(arr1[x]>=arr2[y]){
            result[k++] = arr1[x++];
        }
        else{
            result[k++] = arr2[y++];
        }
    }
    while(x<n){
        result[k++] = arr1[x++];
    }

    while (y<m)
    {
        result[k++] = arr2[y++];
    }
    
}

int main()
{
    int n; cin>>n;
    int arr1[n];
    for(int i = 0; i<n; i++){
        cin>>arr1[i];
    }
    int m; cin>>m;
    int arr2[m];
    for(int i = 0; i<m; i++){
        cin>>arr2[i];
    }
    int result[n+m];

    merge(arr1, n, arr2, m, result);

    for(int i = 0; i<n+m; i++){
        cout<<result[i]<<" ";
    }
    return 0;
}