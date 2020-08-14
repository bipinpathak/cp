#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int R, G, B, i, j, k;
  cin >> R >> G >> B;
  vector<long long> r(R), g(G), b(B);
  vector<vector<vector<long long>>> dp(R + 1, vector<vector<long long>>(G + 1, vector<long long>(B + 1, 0)));
  for (i = 0; i < R; i++) {
    cin >> r[i];
  }
  for (i = 0; i < G; i++) {
    cin >> g[i];
  }
  for (i = 0; i < B; i++) {
    cin >> b[i];
  }
  sort(r.begin(), r.end());
  sort(g.begin(), g.end());
  sort(b.begin(), b.end());
  for (i = 0; i <=R; i++) {
    for (j = 0; j <=G; j++) {
      for (k = 0; k <=B; k++) {
        if (i && j) {
          dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + r[i - 1] * g[j - 1]);
        }
        if (j && k) {
          dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + g[j - 1] * b[k - 1]);
        }
        if (k && i) {
          dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + b[k - 1] * r[i - 1]);
        }
      }
    }
  }
  cout << dp[R][G][B] << endl;
  return 0;
}