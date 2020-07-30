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
    int n, temp;
    cin >> n;
    temp = n;
    string ans = "";
    while(temp>0) {
      ans = '8' + ans;
      temp-=4;
    }
    while(ans.length()<n) {
      ans = '9' + ans;
    }
    cout << ans << endl;
  }
  return 0;
}