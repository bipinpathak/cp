#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, i, optimial, ans = 0;
  cin >> n;
  if(n==1) {
    cin >> optimial;
    cout << optimial;
  } else {
    vector<int> a(n), prefix(n), suffix(n);
    for (i = 0; i < n; i++) {
      cin >> a[i];
      prefix[i] =~ a[i];
      if (i) {
        prefix[i] &= prefix[i - 1];
      }
    }
    for (i = n - 1; i >= 0; i--) {
      suffix[i] = ~a[i];
      if (i + 1 < n) {
        suffix[i] &= suffix[i + 1];
      }
    }
    for (i = 0; i < n; i++) {
      int rest;
      if (i == 0) {
        rest = suffix[i + 1];
      } else if (i == n - 1) {
        rest = prefix[i - 1];
      } else {
        rest = prefix[i - 1] & suffix[i + 1];
      }
      if ((a[i]&rest) >=ans) {
        ans = a[i] & rest;
        optimial = i;
      }
    }
    swap(a[0], a[optimial]);
    for (i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
  }
  return 0;
}