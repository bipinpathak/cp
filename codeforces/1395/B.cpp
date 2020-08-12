#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  vector<vector<int>> visited(n, vector<int>(m, 0));
  cout << x << " " << y << endl;
  visited[x - 1][y - 1] = 1;
  if (x != 1) {
    x = 1;
    cout << x << " " << y << endl;
    visited[x - 1][y - 1] = 1;
  }
  if (y != 1) {
    y = 1;
    cout << x << " " << y << endl;
    visited[x - 1][y - 1] = 1;
  }
  for (int i = 0; i < n; i++) {
    if (i % 2==0) {
      for (int j = 0; j < m; j++) {
        if (!visited[i][j]) {
          cout << i+1 << " " << j+1 << endl;
          visited[i][j] = 1;
        }
      }
    } else {
      for (int j = m-1; j >=0; j--) {
        if (!visited[i][j]) {
          cout << i + 1 << " " << j + 1 << endl;
          visited[i][j] = 1;
        }
      }
    }
  }
    return 0;
}