#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, i, m = 0;
  cin >> n;
  vector<int> a(n);
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] >= 0) {
      a[i] = -1 * (a[i] + 1);
    }
    m = min(m, a[i]);
  }
  if (n % 2) {
    i = 0;
    while (a[i] != m) {
      i++;
    }
    a[i] = -1 * (a[i] + 1);
  }
  for (i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  return 0;
}