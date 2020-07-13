#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n, x, i, ans = 0, count = 0;
    cin >> n >> x;
    vector<long long> a(n);
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (i = n - 1; i >= 0; i--) {
      count++;
      if (count * a[i] >= x) {
        ans++;
        count = 0;
      }
    }
    cout << ans << endl;
  }
  return 0;
}