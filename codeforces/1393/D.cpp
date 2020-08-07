#include <bits/stdc++.h>
using namespace std;
void fillUp(vector<vector<long long>>& grid, vector<vector<long long>>& ans) {
  long long n = grid.size(), m = grid[0].size();
  for (int j = 0; j < m; j++) {
    for (int i = 1; i < n; i++) {
      if (grid[i][j] == grid[i - 1][j]) {
        ans[i][j] = ans[i - 1][j] + 1;
      }
    }
  }
}
void fillDown(vector<vector<long long>>& grid, vector<vector<long long>>& ans) {
  long long n = grid.size(), m = grid[0].size();
  for (int j = 0; j < m; j++) {
    for (int i = n - 2; i >= 0; i--) {
      if (grid[i][j] == grid[i + 1][j]) {
        ans[i][j] = ans[i + 1][j] + 1;
      }
    }
  }
}
void fillA(vector<vector<long long>>& grid, vector<vector<long long>>& up, vector<vector<long long>>& ans) {
  long long n = grid.size(), m = grid[0].size(), last;
  for (int i = 0; i < n; i++) {
    for (int j = m - 1; j >= 0; j--) {
      if (j < m - 1 && grid[i][j] == grid[i][j + 1]) {
        ans[i][j] = min(up[i][j], last + 1);
      }
      last = ans[i][j];
    }
  }
}
void fillS(vector<vector<long long>>& grid, vector<vector<long long>>& up, vector<vector<long long>>& ans) {
  long long n = grid.size(), m = grid[0].size(), last;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j > 0 && grid[i][j] == grid[i][j - 1]) {
        ans[i][j] = min(up[i][j], last + 1);
      }
      last = ans[i][j];
    }
  }
}
void fillT(vector<vector<long long>>& grid, vector<vector<long long>>& down, vector<vector<long long>>& ans) {
  long long n = grid.size(), m = grid[0].size(), last;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j > 0 && grid[i][j] == grid[i][j - 1]) {
        ans[i][j] = min(down[i][j], last + 1);
      }
      last = ans[i][j];
    }
  }
}
void fillC(vector<vector<long long>>& grid, vector<vector<long long>>& down, vector<vector<long long>>& ans) {
  long long n = grid.size(), m = grid[0].size(), last;
  for (int i = 0; i < n; i++) {
    for (int j = m - 1; j >= 0; j--) {
      if (j < m - 1 && grid[i][j] == grid[i][j + 1]) {
        ans[i][j] = min(down[i][j], last + 1);
      }
      last = ans[i][j];
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
  long long n, m, ans = 0;
  cin >> n >> m;
  vector<vector<long long>> grid(n, vector<long long>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char color;
      cin >> color;
      grid[i][j] = color - 'a';
    }
  }
  vector<vector<long long>> up(n, vector<long long>(m, 1)), down, a, t;
  down = a = t = up;
  fillUp(grid, up);
  fillDown(grid, down);
  fillA(grid, up, a);
  fillS(grid, up, up);
  fillT(grid, down, t);
  fillC(grid, down, down);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      long long length = min(min(a[i][j], up[i][j]), min(t[i][j], down[i][j]));
      ans += length;
    }
  }
  cout << ans << endl;
  return 0;
}