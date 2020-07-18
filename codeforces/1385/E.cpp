#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adjacent;
vector<int> visited, order;
void dfs(int i) {
  // cout << "Called " << i + 1 << endl;
  visited[i] = 1;
  for (int j : adjacent[i]) {
    if (!visited[j]) {
      dfs(j);
    }
  }
  // cout << "pushed " << i + 1 << endl;
  order.push_back(i);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges;
    adjacent = vector<vector<int>>(n);
    visited = vector<int>(n, 0);
    for (int i = 0; i < m; i++) {
      int t, x, y;
      cin >> t >> x >> y;
      x--;
      y--;
      edges.push_back(make_pair(x, y));
      if (t) {
        adjacent[x].push_back(y);
      }
    }
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        dfs(i);
      }
    }
    reverse(order.begin(), order.end());
    vector<int> position(n);
    for (int i = 0; i < n; i++) {
      position[order[i]] = i;
    }
    bool flag = true;
    for (int i = 0; i < n; i++) {
      for (int j : adjacent[i]) {
        if (position[i] > position[j]) {
          flag = false;
        }
      }
    }
    if (flag) {
      cout << "YES" << endl;
      for (pair<int, int> edge : edges) {
        int x = edge.first, y = edge.second;
        if (position[x] > position[y]) swap(x, y);
        cout << x + 1 << " " << y + 1 << endl;
      }
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}