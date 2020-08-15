#include <bits/stdc++.h>
using namespace std;
int sum(vector<int>& a, int i) {
  //cout << "cf of " << i;
  int ans = 0;
  while (i) {
    ans += a[i];
    i -= (i & (-1 * i));
  }
  //cout << " = " << ans << endl;
  return ans;
}
int find(vector<int>& a, int& target) {
  //cout << "finding cum f " << target << endl;
  int low = 1, high = a.size() - 1, mid;
  while (low < high) {
    mid = low + (high - low) / 2;
    if (sum(a, mid) < target) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  return low;
}
void update(vector<int>& a, int i, int& add) {
  //cout << "updating " << i << endl;
  while (1) {
    a[i] += add;
    i += (i & (-1 * i));
    if (i >= a.size()) {
      return;
    }
  }
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q, i, temp, add;
  cin >> n >> q;
  vector<int> x(n, 0), a(n + 1, 0);
  for (i = 0; i < n; i++) {
    cin >> temp;
    temp--;
    x[temp]++;
  }
  //cout << "input done" << endl;
  for (i = 0; i < n; i++) {
    update(a, i + 1, x[i]);
  }
  //cout << "initial build done" << endl;
  for (i = 1; i <= n; i++) {
    //cout << a[i] << " ";
  }
  //cout<<endl;
  for (i = 0; i < q; i++) {
    cin >> temp;
    add = 1;
    if (temp < 0) {
      temp *= -1;
      add = -1;
      temp = find(a, temp);
    }
    update(a, temp, add);
  }
  for (i = 0; i <= n; i++) {
    if (a[i]) {
      cout << i << endl;
      return 0;
    }
  }
  cout << "0" << endl;
  return 0;
}