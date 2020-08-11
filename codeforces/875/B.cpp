#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, i, end, added=0, temp;
  cin >> n;
  vector<int> p(n, 0);
  end = n-1;
  cout << "1 ";
  for (i = 0; i < n; i++) {
    cin >>temp;
    temp--;
    p[temp] =1;
    added++;
    while (end>=0 && p[end]) {
      end--;
      added--;
    }
    cout << added+1 << " ";
  }
    return 0;
}