#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long q, x, last = 0;
  cin >> q >> x;
  vector<long long> remainder(x, 0);
  vector<long long> have(q + 1, 0);
  for (int i = 1; i <= q; i++) {
    long long temp;
    cin >> temp;
    temp %= x;
    remainder[temp]++;
    long long add = (remainder[temp] - 1) * x + temp;
    if (add <= q) {
      have[add] = 1;
    }
    while (have[last]) {
      last++;
    }
    cout << last << endl;
  }
  return 0;
}