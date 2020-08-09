#include <bits/stdc++.h>
using namespace std;
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
    int n, m, i, j, ans = 0;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        cin >> grid[i][j];
      }
    }
    for (i = 0; i < m; i++) {
      if (grid[n - 1][i] == 'D') {
        ans++;
      }
    }
    for (i = 0; i < n; i++) {
      if (grid[i][m - 1] == 'R') {
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}