#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long d, m, ans = 0, temp;
  int n, i, j, x = 0;
  cin >> n >> d >> m;
  vector<long long> a(n);
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > m) {
      x++;
    }
  }
  sort(a.begin(), a.end());
  for (i = 1; i < n; i++) {
    a[i] += a[i - 1];
  }
  m = min((long long)x, (n + d) / (d + 1));
  for (i = 0; i <= m; i++) {
    j = max((long long)0, i - x + d * (i - 1));
    temp = a[n - 1];
    if (x <= n - 1) {
      temp += a[n - x - 1];
    }
    if (j) {
      temp -= a[j - 1];
    }
    if (i <= n - 1) {
      temp -= a[n - 1 - i];
    }
    ans = max(ans, temp);
  }
  cout << ans << endl;
  return 0;
}