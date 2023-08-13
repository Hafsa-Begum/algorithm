#include <bits/stdc++.h>
using namespace std;
void init_code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif //ONLINE_JUDGE
}

const int N = 1e3 + 5;
vector<int> adj[N];
int visited[N];

void bfs(int s, stack<int> &st){
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        
        st.push(u);
        for(int v:adj[u]){
            if(visited[v]) continue;
            visited[v] = true;
            q.push(v);
        }
    }
    
}

int main()
{
    // init_code();
    int n, m; cin>>n>>m;
    for(int i = 0; i<m; i++){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    stack<int> st;
    bfs(1, st);

    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    
    
    return 0;
}