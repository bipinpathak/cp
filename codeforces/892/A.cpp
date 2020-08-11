#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, temp;
  long long sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    sum += temp;
  }
    vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  if (sum <= a[n - 1] + a[n - 2]) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}