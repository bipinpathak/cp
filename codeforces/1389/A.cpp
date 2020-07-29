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
    long long l, r, x, y;
    cin >> l >> r;
    if(l*2>r) {
      x = y = -1;
    } else {
      x = l ;
      y = l * 2;
    }
    cout << x << " " <<y << endl;
  }
  return 0;
}