#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, p = 1e9 + 7, i, ans, factorial = 1, power = 1;
  cin >> n;
  for (i = 1; i <= n; i++) {
    factorial = (factorial * i) % p;
  }
  for (i = 1; i < n; i++) {
    power = (power * 2) % p;
  }
  ans = (p + factorial - power) % p;
  cout << ans << endl;
  return 0;
}