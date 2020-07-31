#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, s, f, i, time = 1;
  cin >> n >> m >> s >> f;
  vector<vector<int>> watch;
  for (i = 0; i < m; i++) {
    int t, l, r;
    cin >> t >> l >> r;
    watch.push_back({t, l, r});
  }
  time = 1;
  i = 0;
  while (s != f) {
    if(s<f) {
      if(i!=m && time==watch[i][0] && s>=watch[i][1]-1 && s<=watch[i][2]) {
        cout << "X";
      } else {
        cout << "R";
        s++;
      }
    }  else {
      if (i != m && time == watch[i][0] && s >= watch[i][1] && s <= watch[i][2]+1) {
        cout << "X";
      } else {
        cout << "L";
        s--;
      }
    }
    if (i < m && time == watch[i][0]) {
      i++;
    }
    time++;
  }
  return 0;
}