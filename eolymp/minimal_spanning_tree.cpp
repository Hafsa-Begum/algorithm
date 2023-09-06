#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+9;
int parent[N];
int parentSize[N];

void dsu_set(int n){
    for(int i = 1; i<=n; i++){
        parent[i] = -1;
        parentSize[i] = 1;
    }
}
int dsu_find(int node){
    while (parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}
void dsu_union(int a, int b){
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if(leaderA != leaderB){
        if(parentSize[leaderA]>parentSize[leaderB]){
            parent[leaderB] = leaderA;
            parentSize[leaderA]+=parentSize[leaderB];
        }
        else{
            parent[leaderA] = leaderB;
            parentSize[leaderB]+=parentSize[leaderA];
        }
    }
}
class Edge{
    public:
    int a, b, w; 
    Edge(int a, int b, int w){
        this->a = a;
        this->b = b;
        this->w = w;
    }
};
bool cmp(Edge a, Edge b){
    return a.w<b.w;
}
int main()
{
    int n, e; cin>>n>>e;
    dsu_set(n);
    vector<Edge> v;
    vector<Edge> ans;
    int cmp = n;
    while(e--){
        int a, b, w; cin>>a>>b>>w;
        v.push_back(Edge(a, b, w));
    }
    sort(v.begin(), v.end(), cmp);
    for(Edge val:v){
        int leaderA = dsu_find(val.a);
        int leaderB = dsu_find(val.b);
        if(leaderA == leaderB) continue;
        cmp--;
        ans.push_back(Edge(val.a, val.b, val.w));
        dsu_union(val.a, val.b);
    }
    if(cmp>1){
        cout<<"Not Possible"<<endl;
    }
    else{
        long long sum = 0;
        for(Edge x:ans){
        sum+=x.w;
    }
        cout<<e-(ans.size()-1)<<" ";
        cout<<sum<<endl;
    }
    
    return 0;
}
// link - https://www.eolymp.com/en/problems/3835