#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, i, ans, frontMax;
  cin >> n;
  ans = n;
  vector<int> a(n);
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  unordered_map<int, int> front;
  unordered_set<int>back;
  for (i = 0; i < n; i++) {
    if (front.find(a[i]) != front.end()) {
      break;
    }
    front[a[i]] = i;
  }
  frontMax = i;
  ans = n - frontMax;
  for (i = n - 1; i >= 0; i--) {
    if (back.find(a[i]) != back.end()) {
      ans = min(ans, i + 1);
      break;
    }
    back.insert(a[i]);
    if (front.find(a[i]) != front.end()) {
      frontMax = min(frontMax, front[a[i]]);
    }
    if (i > frontMax) {
      int start = frontMax;
      ans = min(ans, i - start);
    }
  }
  cout << ans << endl;
  return 0;
}