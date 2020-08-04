#include <bits/stdc++.h>
using namespace std;
void fill(int node, vector<int> &pass, vector<int> &population, vector<vector<int>> &adjacency, vector<int> &visited) {
  visited[node] = 1;
  pass[node] = population[node];
  for (int next : adjacency[node]) {
    if(!visited[next]) {
      fill(next, pass, population, adjacency, visited);
      pass[node] += pass[next];
    }
  }
}
void verify(int node, vector<int> &bad, vector<int> &population, vector<vector<int>> &adjacency,vector<int> &visited, bool &possible) {
  if(possible) {
    visited[node] = 1;
    int total = population[node];
    for(int next : adjacency[node]) {
      if(!visited[next]) {
        verify(next, bad, population, adjacency, visited, possible);
        if(!possible) {
          return;
        }
        total += bad[next];
      }
    }
    if(bad[node]>total) {
      possible = false;
    }
  }
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m, i;
    cin >> n >> m;
    vector<int> population(n), happiness(n), pass(n), visited(n, 0);
    vector<vector<int>> adjacency(n);
    for (i = 0; i < n; i++) {
      cin >> population[i];
    }
    for (i = 0; i < n; i++) {
      cin >> happiness[i];
    }
    for (i = 0; i < n - 1; i++) {
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      adjacency[x].push_back(y);
      adjacency[y].push_back(x);
    }
    fill(0, pass, population, adjacency, visited);
    bool possible = true;
    for (i = 0; i < n ; i++) {
      pass[i] -= happiness[i];
      if(pass[i]<0 || pass[i]%2) {
        possible = false;
        break;
      }
      pass[i] /= 2;
    }
    visited = vector<int>(n, 0);
    verify(0, pass, population, adjacency, visited, possible);
    if (possible) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}