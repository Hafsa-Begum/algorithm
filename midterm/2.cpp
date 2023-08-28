#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main()
{
    int n;
    cin>>n;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    while (n--)
    {
       int a, b;
       cin>>a>>b;
       pq.push({a,b});
    }
    while (!pq.empty())
    {
        cout<<pq.top().first<<" "<<pq.top().second<<endl;
        pq.pop();
    }    
    return 0;
}

// 6
// 1 2
// 1 4
// 1 5
// 3 4
// 3 2
// 3 5