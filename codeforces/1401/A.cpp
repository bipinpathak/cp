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
  while(t--) {
    int a, d, ans=0;
    cin >> a >> d;
    if(a>d) {
      if ((a - d) % 2) {
        ans = 1;
      }
    } else {
      ans = d - a;
    }
    cout << ans << endl;
  }
  return 0;
}