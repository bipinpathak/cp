#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, i;
    cin >> n;
    vector<int> a(n);
    int ans = 0;
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (a[0] != 1) {
      ans++;
    }
    for (i = 1; i < n; i++) {
      if (ans < 2 && a[i] != i + 1 && a[i - 1] == i) {
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
