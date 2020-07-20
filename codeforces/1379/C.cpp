#include <bits/stdc++.h>
using namespace std;
bool custom(vector<long long> a, vector<long long> b) { return a[1] < b[1]; }
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    vector<vector<long long>> f(m, vector<long long>(2));
    for (long long i = 0; i < m; i++) {
      cin >> f[i][0] >> f[i][1];
    }
    sort(f.begin(), f.end(), custom);
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    long long ans = 0, sum = 0;
    for (long long i = 0; i < m; i++) {
      while (pq.size() >= n || (pq.size() && pq.top() < f[i][1])) {
        sum -= pq.top();
        pq.pop();
      }
      ans =
          max(ans, (long long)(sum + f[i][0] + (n - pq.size() - 1) * f[i][1]));
      pq.push(f[i][0]);
      sum += f[i][0];
    }
    cout << ans << endl;
  }
  return 0;
}