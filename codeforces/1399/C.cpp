#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, i, j, ans = 0;
    cin >> n;
    vector<int> a(n);
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (i = 0; i < n; i++) {
      for (j = i + 1; j < n; j++) {
        int target = a[i] + a[j], left=0, right=n-1, count=0;
        while (left < right) {
          if (a[left] + a[right] == target) {
            count++;
            left++;
            right--;
          } else if (a[left] + a[right] > target) {
            right--;
          } else {
            left++;
          }
        }
        ans = max(ans, count);
      }
    }
    cout << ans << endl;
  }
  return 0;
}