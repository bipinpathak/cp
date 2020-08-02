#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string a, b;
  cin >> a >> b;
  long long n = a.size(), m = b.size(), i, ans = 0;
  vector<long long> store(n, 0);
  for (i = 0; i < n; i++) {
    if (a[i] == '1') {
      store[i]++;
    }
    if (i) {
      store[i] += store[i - 1];
    }
  }
  for (i = 0; i < m; i++) {
    int one, start = max(i + n - m, (long long)0), end = min(i, n - 1);
    one = store[end] - (start ? store[start - 1] : 0);
    if (b[i] == '0') {
      ans += one;
    } else {
      ans += end - start - one + 1;
    }
  }
  cout << ans << endl;
  return 0;
}