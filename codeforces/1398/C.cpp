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
    int n;
    long long ans = 0, sum = 0;
    unordered_map<int, int> f;
    f[0] = 1;
    string s;
    cin >> n >> s;
    for (char c : s) {
      sum += c - '0' - 1;
      if (f.find(sum) == f.end()) {
        f[sum] = 0;
      } else {
        ans += f[sum];
      }
      f[sum]++;
    }
    cout << ans << endl;
  }
  return 0;
}