#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, temp, ans=0, sum=0, i;
  cin >> n >> m;
  vector<int> a(m, 0);
  for (i = 0; i < n; i++) {
    cin >> temp;
    temp--;
    a[temp]++;
  }
  sort(a.begin(), a.end());
  for (i = 0; i < m; i++) {
    sum += a[i];
  }
  for (i = 0; i < m; i++) {
    sum -= a[i];
    ans += sum * a[i];
  }
  cout << ans << endl;
  return 0;
}