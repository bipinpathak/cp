#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long ans=0, i, a, b, nSwords, nAxes, wSword, wAxe, axeA, axeB, swordA, swordB;
  cin >> a >> b >> nSwords >> nAxes >> wSword >> wAxe;
  if(wAxe>wSword) {
    swap(wAxe, wSword);
    swap(nAxes, nSwords);
  }
  for (i = 0; i <=nAxes; i++) {
    axeA = axeB = swordA = swordB = 0;
    axeA = min(i, a / wAxe);
    swordA = min(nSwords, (a - wAxe * axeA) / wSword);
    axeB = min(nAxes - axeA, b / wAxe);
    swordB = min(nSwords - swordA, (b - wAxe * axeB) / wSword);
    ans = max(ans, axeB + axeA + swordB + swordA);
  }
  cout << ans << endl;
}
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
    solve();
  }
  return 0;
}