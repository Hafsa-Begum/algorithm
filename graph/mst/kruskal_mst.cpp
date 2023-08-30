#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
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
    while(e--){
        int a, b, w; cin>>a>>b>>w;
        v.push_back(Edge(a, b, w));
    }
    sort(v.begin(), v.end(), cmp);
    for(Edge val:v){
        int leaderA = dsu_find(val.a);
        int leaderB = dsu_find(val.b);
        if(leaderA == leaderB) continue;
        ans.push_back(Edge(val.a, val.b, val.w));
        dsu_union(val.a, val.b);
    }
    for(Edge x:ans){
        cout<<x.a<<" "<<x.b<<" "<<x.w<<endl;
    }
    return 0;
}

/*
input:
7 11
1 2 5
1 3 7
3 2 9
3 5 8
5 6 5
3 6 7
2 4 6
2 6 15
4 6 8
4 7 11
6 7 9

output:
1 2 5
5 6 5
2 4 6
1 3 7
3 6 7
6 7 9
*/