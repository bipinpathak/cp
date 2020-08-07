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
    int n, i, temp;
    cin >> n;
    vector<int> a(n, 0);
    for (i = 0; i < n; i++) {
      cin >> temp;
      temp--;
      a[temp]++;
    }
    sort(a.begin(), a.end(), greater<int>());
    int sum = 0, largest = a[0], ans = 0;
    for (i = 1; i < n && a[i] > 0; i++) {
      if (a[i] == largest) {
        ans++;
      } else {
        sum += a[i];
      }
    }
    ans += sum / (largest - 1);
    cout << ans << endl;
  }
  return 0;
}