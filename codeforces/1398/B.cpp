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
    string s;
    cin >> s;
    vector<int> sums;
    int ans = 0, count = 0, n;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '1') {
        count++;
      } else {
        if (count) {
          sums.push_back(count);
        }
        count = 0;
      }
    }
    if (count) {
      sums.push_back(count);
    }
    n = sums.size();
    sort(sums.begin(), sums.end());
    for (int i = n - 1; i >= 0; i--) {
      if ((n - i) % 2) {
        ans += sums[i];
      }
    }
    cout << ans << endl;
  }
  return 0;
}