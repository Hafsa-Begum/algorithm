#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e5+9;
vector<pii> v[N];
bool visited[N];
class Edge{
    public:
    int a, b, w;
    Edge(int a, int b, int w){
        this->a = a;
        this->b = b;
        this->w = w;
    }
};
class cmp{
    public:
    bool operator()(Edge a, Edge b){
        return a.w>b.w;
    }
};
void prims(int s, int n){
    priority_queue<Edge, vector<Edge>, cmp> pq;
    pq.push(Edge(s, s, 0));
    vector<Edge> edgeList;
    int cnt=0;
    while (!pq.empty())
    {
        Edge parent = pq.top();
        pq.pop();
        int a = parent.a;
        int b = parent.b;
        int w = parent.w;
        if(visited[b]) continue;
        visited[b] = true;
        cnt++;
        edgeList.push_back(parent);
        for(pii child:v[b]){
            if(!visited[child.first]){
                pq.push(Edge(b, child.first, child.second));
            }
        }
    }
    edgeList.erase(edgeList.begin());
    long long sum = 0;
    for(Edge e:edgeList){
        sum += e.w;
    }
    if(cnt == n){
        cout<<sum<<endl;
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
}
int main()
{
    int n, e; cin>>n>>e;
    while (e--)
    {
        int a, b, w; cin>>a>>b>>w;
        v[a].push_back({b, w});
        v[b].push_back({a, w});
    }
    prims(1, n);
    return 0;
}