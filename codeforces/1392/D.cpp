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
    int n, ans = 0, i, count = 1, k;
    string s;
    cin >> n >> s;
    vector<int> store;
    for (i = 1; i < n; i++) {
      if (s[i] == s[i - 1]) {
        count++;
      } else {
        store.push_back(count);
        count = 1;
      }
    }
    if (store.size() && s[n - 1] == s[0]) {
      store[0] += count;
    } else {
      store.push_back(count);
    }
    for (int i : store) {
      ans += i / 3;
    }
    if (store.size() == 1 && n%3!=0) {
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}