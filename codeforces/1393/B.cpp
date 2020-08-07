#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, temp, i;
  cin >> n;
  vector<int> f(10e5 + 1, 0);
  unordered_set<int> two, four, six, eight;
  for (i = 0; i < n; i++) {
    cin >> temp;
    f[temp]++;
  }
  for (i = 0; i < 10e5 + 1; i++) {
    if (f[i] >= 8) {
      eight.insert(i);
    } else if (f[i] >= 6) {
      six.insert(i);
    } else if (f[i] >= 4) {
      four.insert(i);
    } else if (f[i] >= 2) {
      two.insert(i);
    }
  }
  int q;
  cin >> q;
  while (q--) {
    char event;
    cin >> event >> temp;
    if (event == '+') {
      f[temp]++;
      if (f[temp] >= 8) {
        six.erase(temp);
        eight.insert(temp);
      } else if (f[temp] >= 6) {
        four.erase(temp);
        six.insert(temp);
      } else if (f[temp] >= 4) {
        two.erase(temp);
        four.insert(temp);
      } else if (f[temp] >= 2) {
        two.insert(temp);
      }
    } else {
      f[temp]--;
      if (f[temp] == 7) {
        eight.erase(temp);
        six.insert(temp);
      } else if (f[temp] == 5) {
        six.erase(temp);
        four.insert(temp);
      } else if (f[temp] == 3) {
        four.erase(temp);
        two.insert(temp);
      } else if (f[temp] == 1) {
        two.erase(temp);
      }
    }
    if ((eight.size() > 0) || (six.size() > 1) || (six.size() > 0 && (four.size() > 0 || two.size() > 0)) || (four.size() > 1) || (four.size() > 0 && two.size() > 1)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}