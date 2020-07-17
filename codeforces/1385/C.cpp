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
    vector<int> a(n);
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    i = n - 2;
    while (i >= 0 && a[i] >= a[i + 1]) {
      i--;
    }
    while (i >= 0 && a[i] <= a[i + 1]) {
      i--;
    }
    cout << i + 1 << endl;
  }
  return 0;
}