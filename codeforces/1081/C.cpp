#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, k, p = 998244353, ans, i, j;
  cin >> n >> m >> k;
  ans = m;
  m--;
  for (i = 0; i < k; i++) {
    ans = (ans * m) % p;
  }
  vector<vector<long long>> ncr(n, vector<long long>(k + 1, 1));
  for (i = 1; i < n; i++) {
    for (j = 1; j <min(i,k+1); j++) {
      ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j])%p;
    }
  }
  ans = (ans * ncr[n - 1][k]) % p;
  cout << ans << endl;
  return 0;
}