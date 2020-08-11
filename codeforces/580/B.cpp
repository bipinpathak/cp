#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, d, i, m, s, ans = 0, sum = 0, j;
  cin >> n >> d;
  vector<pair<long long, long>> friends(n);
  for (i = 0; i < n; i++) {
    cin >> m >> s;
    friends[i] = make_pair(m, s);
  }
  sort(friends.begin(), friends.end());
  i = 0;
  j = 0;
  while (j < n) {
    while (friends[j].first - friends[i].first >=d) {
      sum -= friends[i].second;
      i++;
    }
    sum += friends[j].second;
    ans = max(ans, sum);
    j++;
  }
  cout << ans << endl;
  return 0;
}