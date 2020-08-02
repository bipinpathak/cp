#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, i, largest;
    bool possible = true;
    cin >> n;
    vector<int> p(n);
    for (i = 0; i < n; i++) {
      cin >> p[i];
    }
    i = n - 1;
    while (i >= 0 && p[i] == n - i) {
      i--;
    }
    if(i>=0) {
      largest = p[i];
    }
    i--;
    while(i>=0 && possible) {
      if(p[i]!=p[i+1]-1 && p[i]<largest) {
        possible = false;
      }
      largest = max(largest, p[i]);
      i--;
    }
    if(possible) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}