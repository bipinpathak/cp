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
    long long n, k, start = 0, i;
    string s;
    cin >> n >> k >> s;
    while (start < n && s[start] == '0') {
      start++;
    }
    for (i = start; i < n; i++) {
      if (s[i] == '0') {
        swap(s[i], s[i - min(i - start, k)]);
        k -= i - start;
        if (k <= 0) {
          break;
        }
        start++;
      }
    }
    cout << s << endl;
  }
  return 0;
}