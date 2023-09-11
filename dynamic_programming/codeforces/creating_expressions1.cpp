// // link - https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/V

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     long long x; cin>>n>>x;
//     long long a[n];
//     for(int i= 0; i<n; i++){
//         cin>>a[i];
//     }
//     unordered_set<int> sums;
//     sums.insert(0);

//     for(int i = 0; i<n; i++){
//         unordered_set<int> newSums;
//         for(int sum:sums){
//             newSums.insert(sum+a[i]);
//             newSums.insert(sum-a[i]);
//         }
//         sums = newSums;
//     }
//     if(sums.find(x) != sums.end()){
//         cout<<"YES"<<endl;
//     }
//     else{
//         cout<<"NO"<<endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int a[21];
int size, result;
bool check_result(long long int sum, int i){
    if(i == size){
        return sum == result;
    }
    bool op1 = check_result(sum + a[i], i++);
    bool op2 = check_result(sum - a[i], i++);
    return op1 || op2;
}
int main()
{
    cin>>size>>result;
    for (int i = 0; i < size; i++)
    {
        cin>>a[i];
    }
    if(check_result(a[0], 1)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}