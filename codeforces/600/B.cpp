#include <bits/stdc++.h>
using namespace std;
int find(int target, vector<int>& a) {
  int left=0, right=a.size()-1, mid;
  while (left < right) {
    mid = left + (right - left) / 2;
    if (a[mid] > target) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return a[left]>target?left:left+1;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, i;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  for (i = 0; i < m; i++) {
    cin >> b[i];
    cout << find(b[i], a) << " ";
  }
  return 0;
}