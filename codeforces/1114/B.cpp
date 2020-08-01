#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, k, i, count = 0, sum = 0;
  cin >> n >> m >> k;
  vector<long long> a(n), copy, breaks;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  copy = a;
  sort(copy.begin(), copy.end());
  unordered_map<long long, long long> discard;
  for (i = 0; i < n - m * k; i++) {
    sum -= copy[i];
    if (discard.find(copy[i]) == discard.end()) {
      discard[copy[i]] = 0;
    }
    discard[copy[i]]++;
  }
  for (i = 0; i < n; i++) {
    sum += a[i];
    if (discard.find(a[i]) == discard.end()) {
      count++;
      if (count == m) {
        breaks.push_back(i+1);
        count = 0;
      }
    } else {
      discard[a[i]]--;
      if (discard[a[i]] == 0) {
        discard.erase(a[i]);
      }
    }
  }
  breaks.pop_back();
  cout << sum << endl;
  for(long long x : breaks) {
    cout << x << " ";
  }
  return 0;
}