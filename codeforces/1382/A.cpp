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
    int n, m, ans=-1;
    cin >> n >> m;
    vector<int> a(n), b(m);
    unordered_set<int> f;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      f.insert(a[i]);
    }
    for (int i = 0; i < m; i++) {
      cin >> b[i];
      if(ans==-1 && f.find(b[i])!=f.end()) {
        ans = b[i];
      }
    }
    if(ans==-1) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl << "1 " << ans << endl;
      ;
    }
  }
  return 0;
}