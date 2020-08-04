#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> &visited, vector<int> &next, vector<int> &order) {
  visited[node] = 1;
  if (next[node] != -1 && !visited[next[node]]) {
    dfs(next[node], visited, next, order);
  }
  order.push_back(node);
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, i;
  long long ans = 0;
  cin >> n;
  vector<long long> a(n);
  vector<int> b(n), visited(n, 0), order, front, back;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n; i++) {
    cin >> b[i];
    if (b[i] != -1) {
      b[i]--;
    }
  }
  for (i = 0; i < n; i++) {
    if (!visited[i]) {
      dfs(i, visited, b, order);
    }
  }
  reverse(order.begin(), order.end());
  for (i = 0; i < n; i++) {
    int node = order[i];
    ans += a[node];
    if(a[node]>0 && b[node]!=-1) {
      a[b[node]] += a[node];
      front.push_back(node);
    } else {
      back.push_back(node);
    }
  }
  cout << ans << endl;
  for(int i : front) {
    cout << i+1 << " ";
  }
  reverse(back.begin(),back.end());
  for(int i :back) {
    cout << i+1 << " ";
  }
  return 0;
}