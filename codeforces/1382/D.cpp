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
    int n, i, j, count = 0, last = 0;
    cin >> n;
    n *= 2;
    vector<int> a(n), sum;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] > a[last]) {
        sum.push_back(count);
        last = i;
        count = 0;
      }
      count++;
    }
    sort(sum.begin(), sum.end());
    n /= 2;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (i = 0; (i < sum.size()) && (dp[n] == 0); i++) {
      vector<int> current(n + 1, 0);
      for (j = 0; (j <= n) && (dp[n] == 0); j++) {
        if (dp[j] == 0 && j >= sum[i] && dp[j - sum[i]] &&
            !current[j - sum[i]]) {
          dp[j] = 1;
          current[j] = 1;
        }
      }
    }
    if (dp[n]) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}