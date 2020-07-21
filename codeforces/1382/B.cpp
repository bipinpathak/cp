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
    int n, v = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
      if(a[i]==1) {
        v = !v;
      } else {
        v = 1;
      }
    }
    if(v) {
      cout << "First" << endl;
    } else {
      cout << "Second" << endl;
    }
  }
  return 0;
}