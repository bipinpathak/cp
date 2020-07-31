#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, i;
  cin >> n;
  vector<vector<int>> b(n, vector<int>(n));
  vector<int> a(n, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> b[i][j];
      if (j<i) {
        a[i] |= b[i][j];
        a[j] |= b[i][j];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  return 0;
}