#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<ll> x(n), y(n);
    for(int i=0; i<n; i++) {
        cin>>x[i]>>y[i];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    ll ans=(x[n/2]-x[(n-1)/2]+1)*(1+y[n/2]-y[(n-1)/2]);
    cout<<ans<<endl;
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

