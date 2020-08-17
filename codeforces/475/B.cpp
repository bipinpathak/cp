#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  string row, col, ans = "NO";
  cin >> n >> m >> row >> col;
  if ((row.front() == '>' && row.back() == '<' && col.front() == '^' && col.back() == 'v') || (row.front() == '<' && row.back() == '>' && col.front() == 'v' && col.back() == '^')) {
    ans = "YES";
  }
  cout << ans << endl;
  return 0;
}