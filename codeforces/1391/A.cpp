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
    int n, i=0, temp=1;
    cin>>n;
    vector<int> a(n);
    for (i = 0; i < n/2; i++) {
      a[i] = n - 2 * i;
    }
    a[i] = 1;
    for (i = n - 1; i > n / 2; i--) {
      a[i] = 2 * i + 1 - n;
    }
      for (i = 0; i < n; i++) {
        cout << a[i] << " ";
      }
    cout << endl;
  }
  return 0;
}