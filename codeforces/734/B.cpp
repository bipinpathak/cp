#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    ll k2, k3, k5, k6;
    cin>>k2>>k3>>k5>>k6;
    ll x=min(k2, min(k5, k6));
    k2-=x;
    ll y=min(k2, k3);
    ll ans=32*y+256*x;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

