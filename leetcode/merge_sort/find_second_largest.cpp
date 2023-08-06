// link - https://www.codingninjas.com/studio/problems/second-largest-element-in-the-array_873375?leftPanelTab=0

#include <bits/stdc++.h> 

int findSecondLargest(int n, vector<int> &arr)
{
    // Write your code here.
    int first = INT_MIN;
    int second = INT_MIN;

    for(int i = 0; i<n ; i++){
        if(arr[i]>first){
            second = first;
            first = arr[i];
        }

        else if(arr[i]>second && arr[i]<first){
            second = arr[i];
        }
    }

    if(second == INT_MIN) return -1;
    else return second;
}