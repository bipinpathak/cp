#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, a, b, x = 1;
  cin >> n >> a >> b;
  for (int i = max(1, n-b); i <=min(n-1, a); i++) {
    x = max(x, min(a / i, b / (n - i)));
  }
  cout << x;
  return 0;
}