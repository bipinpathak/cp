#include <bits/stdc++.h>
using namespace std;
int cost(string s, int shift) {
  char x = 'a';
  x += shift;
  int n = s.length(), ans = 0;
  if (n == 1) {
    if (s[0] != x) {
      ans++;
    }
  } else {
    int front = 0, back = 0, i;
    for (i = 0; i < n / 2; i++) {
      if (s[i] == x) {
        front++;
      }
    }
    while (i < n) {
      if (s[i] == x) {
        back++;
      }
      i++;
    }
    n /= 2;
    shift++;
    ans = min(n - front + cost(s.substr(n, n), shift),
              n - back + cost(s.substr(0, n), shift));
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, i;
    string s;
    cin >> n >> s;
    cout << cost(s, 0) << endl;
  }
  return 0;
}