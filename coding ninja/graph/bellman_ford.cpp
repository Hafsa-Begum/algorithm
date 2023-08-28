// link - https://www.codingninjas.com/studio/problems/bellmon-ford_2041977

vector<int> bellmonFord(int n, int m, int s, vector<vector<int>> &edges) {
  // Write your code here.
  int dist[n + 1];
  for (int i = 0; i <= n; i++) {
    dist[i] = 1e8;
  }
  vector<int> ans;
  dist[s] = 0;
  for (int k = 1; k <= n - 1; k++) {
    for (int i = 0; i < m; i++) {
      if (dist[edges[i][0]] + edges[i][2] < dist[edges[i][1]]) {
        dist[edges[i][1]] = dist[edges[i][0]] + edges[i][2];
      }
    }
  }
  for (int i = 0; i <= n; i++) {
    ans.push_back(dist[i]);
  }
  return ans;
}