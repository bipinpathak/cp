#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, i, j, start, end, length, x, k, y, ans = -1, maximum;
  cin >> n >> m >> x >> k >> y;
  vector<long long> a(n + 2), b(m + 2);
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (i = 1; i <= m; i++) {
    cin >> b[i];
  }
  a[0] = b[0] = a[n + 1] = b[m + 1] = -1;
  if (m <= n) {
    ans = 0;
    i = 0;
    j = 0;
    while (i < n + 2 && j < m + 2) {
      while (i < n + 2 && j < m + 2 && a[i] == b[j]) {
        i++;
        j++;
      }
      if (i == n + 2 && j == m + 2) {
        break;
      } else if (i == n + 2) {
        ans = -1;
        break;
      }
      start = i;
      maximum = -1;
      while (i < n + 2 && (j == m + 2 || a[i] != b[j])) {
        maximum = max(maximum, a[i]);
        i++;
      }
      end = i - 1;
      length = end - start + 1;
      if (i == n + 2 && j != m + 2) {
        ans = -1;
        break;
      }
      if (k * y <= x) {
        if (a[start - 1] > maximum || a[end + 1] > maximum) {
          ans = ans + length * y;
        } else if (length >= k) {
          ans = ans + x + y * (length - k);
        } else {
          ans = -1;
          break;
        }
      } else {
        if (length >= k) {
          ans = ans + x * (length / k) + y * (length % k);
        } else if (a[start - 1] > maximum || a[end + 1] > maximum) {
          ans = ans + length * y;
        } else {
          ans = -1;
          break;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}