#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

void solve() {
    ll p, ans=1e18, t=3;
    cin>>p;
    while(t--) {
        ll a;
        cin>>a;
        ans=min(ans, (((p+a-1)/a)*a)-p);
    }
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

