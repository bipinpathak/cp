#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, count=0;
  cin >> n;
  vector<int> a(n), b;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b = a;
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    if(a[i]!=b[i]) {
      count++;
    }
  }
  if(count<=2) {
    cout << "YES" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}