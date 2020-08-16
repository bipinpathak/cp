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
    int n, i, low=INT_MAX, high=0 ;
    cin>>n;
    vector<int> a(n);
    for (i = 0; i < n; i++) {
      cin >> a[i];
      low = min(low, a[i]);
      high = max(high, a[i]);
    }
    if (low == high) {
      cout << n << endl;
    } else {
      cout << "1" << endl;
    }
  }
  return 0;
}