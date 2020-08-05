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
    int n, i, count = 0;
    string s;
    cin >> n >> s;
    vector<int> ans(n);
    stack<int> one, zero;
    for (i = 0; i < n; i++) {
      if (s[i] == '0') {
        if (one.size() == 0) {
          count++;
          one.push(count);
        }
        ans[i] = one.top();
        one.pop();
        zero.push(ans[i]);
      } else {
        if (zero.size() == 0) {
          count++;
          zero.push(count);
        }
        ans[i] = zero.top();
        zero.pop();
        one.push(ans[i]);
      }
    }
    cout << count << endl;
    for (i = 0; i < n; i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }
  return 0;
}