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
    int n, i, j, count = 0;
    string a, b;
    cin >> n >> a >> b;
    vector<int> ans;
    for (i = n - 1; i >= 0; i--) {
      if (a[i] != b[i]) {
        if (a[0] == b[i]) {
          ans.push_back(1);
          a[0] = (b[i] == '0') ? '1' : '0';
        }
        ans.push_back(i + 1);
        reverse(a.begin(), a.begin() + i + 1);
        for (j = 0; j <= i; j++) {
          a[j] = (a[j] == '0') ? '1' : '0';
        }
      }
    }
    cout << ans.size();
    for (int i : ans) {
      cout << " " << i;
    }
    cout << endl;
  }
  return 0;
}