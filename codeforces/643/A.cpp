#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, i, j, k;
  cin >> n;
  vector<int> a(n), ans(n, 0);
  for (i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  for (i = 0; i < n; i++) {
    vector<int> f(n, 0);
    int maxElement = 0;
    for (j = i; j < n; j++) {
      f[a[j]]++;
      if (f[a[j]] > f[maxElement] || (f[a[j]] == f[maxElement] && a[j] < maxElement)) {
        maxElement = a[j];
      }
      ans[maxElement]++;
    }
  }
  for (i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}