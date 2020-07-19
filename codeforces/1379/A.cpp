#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, i, j, count = 0, k, l;
    string s, temp, pattern = "abacaba";
    cin >> n >> s;
    bool possible = false;
    for (i = 0; i < n; i++) {
      for (j = i; j < n && j < i + 7; j++) {
        if (s[j] != pattern[j - i]) {
          break;
        }
      }
      if (j == i + 7) {
        count++;
      }
    }
    if (count == 1) {
      possible = true;
    } else if (count == 0) {
      for (i = 0; i < n; i++) {
        temp = s;
        for (j = i; j < n && j < i + 7; j++) {
          if (temp[j] != pattern[j - i]) {
            if (temp[j] == '?') {
              temp[j] = pattern[j - i];
            } else {
              break;
            }
          }
        }
        count = 0;
        for (k = 0; k < n; k++) {
          for (l = k; l < n && l < k + 7; l++) {
            if (temp[l] != pattern[l - k]) {
              break;
            }
          }
          if (l == k + 7) {
            count++;
          }
        }
        if (count == 1) {
          s = temp;
          possible = true;
          break;
        }
      }
    }
    if (possible) {
      for (i = 0; i < n; i++) {
        if (s[i] == '?') {
          s[i] = 'z';
        }
      }
      cout << "YES" << endl << s << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}