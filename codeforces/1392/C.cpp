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
    int n, i;
    cin >> n;
    vector<int> a(n);
    long long ans = 0;
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (i = 1; i < n; i++) {
      ans = ans + max(0, a[i - 1] - a[i]);
    }
    cout << ans << endl;
  }
  return 0;
}