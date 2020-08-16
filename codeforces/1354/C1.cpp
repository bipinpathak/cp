#include <bits/stdc++.h>
using namespace std;
void solve() {
  long double n, ans;
  cin >> n;
  ans = 1/tan(acos(0) / n);
  cout << ans << endl;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(10);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}