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
    int n, i, low=1e9, high=-1,k,m=0;
    cin >> n;
    vector<int> a(n);
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (i = 0; i < n; i++) {
      if(a[i]==-1) {
        if (i && a[i - 1] != -1) {
          low = min(low, a[i - 1]);
          high = max(high, a[i - 1]);
        }
        if (i < n - 1 && a[i + 1] != -1) {
          low = min(low, a[i + 1]);
          high = max(high, a[i + 1]);
        }
      }
    }
    k = low + (high - low) / 2;
    for (i = 0; i < n; i++) {
      if(a[i]==-1) {
        a[i] = k;
      }
    }
    for (i = 1; i < n; i++) {
      m = max(m, abs(a[i] - a[i - 1]));
    }
    cout << m << " " << k << endl;
  }
  return 0;
}