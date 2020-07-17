#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, i;
    cin >> n;
    vector<int> a(2 * n), f(n + 1, 0);
    for (i = 0; i < 2 * n; i++) {
      cin >> a[i];
      if (f[a[i]] == 0) {
        f[a[i]]++;
        cout << a[i] << " ";
      }
    }
    cout << endl;
  }
  return 0;
}