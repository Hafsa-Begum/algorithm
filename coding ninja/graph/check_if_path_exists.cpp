// link - https://www.codingninjas.com/studio/problems/path-between-two-vertices-in-a-directed-graph_920534

#include <bits/stdc++.h> 

void dfs (int s, vector<vector<int> > &adj, vector<bool> &visited){
    visited[s] = true;
    for(auto v:adj[s]){
        if(visited[v]) continue;
        visited[v] = true;
        dfs(v, adj, visited);
    }
}

bool checkPathExists(int v, int e, int source, int destination, vector<vector<int>> &edges) 
{
    vector<bool> visited(v, false);
    
    vector<vector<int> > adj(v);
    for(int i = 0; i < e; i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        
    }

    // Start DFS from the source node
    dfs(source, adj, visited);
    
    return visited[destination];  // Return if the destination was visited or not
}
