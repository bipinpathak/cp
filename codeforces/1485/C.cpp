#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll x, y;
    cin>>x>>y;
    ll ans=0;
    ll b=1;
    while(b<=y && b-1<=(x)/(b+1)) {
        ans+=b-1;
        b++;
    }
    while(b<=min(y, x-1)) {
        ll val=x/(b+1), key=min(y, x-1);
        key=min(key, x/val - 1);
        ans+=val*(key-b+1);
        b=key+1;
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

