#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long ans = 0, count = 1;
  int n, i = 1;
  char first, last;
  string s;
  cin >> s;
  n = s.length();
  vector<long long> gaps;
  for (i = 1; i < n; i++) {
    if (s[i] == s[i - 1]) {
      count++;
    } else {
      if (s[i] == 'o') {
        count--;
      }
      if (count == 0 && gaps.size()) {
        count = gaps[(int)gaps.size() - 1] + 1;
        gaps.pop_back();
      } else if (count) {
        if (gaps.size() == 0) {
          first = s[i - 1];
        }
        last = s[i - 1];
        gaps.push_back(count);
        count = 1;
      } else {
        count = 1;
      }
    }
  }
  if (s[i - 1] == 'v') {
    count--;
  }
  if (count) {
    if (gaps.size() == 0) {
      first = s[i - 1];
    }
    last = s[i - 1];
    gaps.push_back(count);
  }
  int start = 0, end = gaps.size() - 1;
  if (first == 'o') {
    start++;
  }
  if (last == 'o') {
    end--;
  }
  if (end > start + 1) {
    i = start;
    long long sum = 0, prefix = 0;
    while (i <= end) {
      if ((i - start) % 2 == 0) {
        sum += gaps[i];
      }
      i++;
    }
    for (i = start; i <= end; i++) {
      if ((i - start) % 2 == 0) {
        prefix += gaps[i];
        sum -= gaps[i];
      } else {
        ans += prefix * gaps[i] * sum;
      }
    }
  }
  cout << ans << endl;
  return 0;
}