#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, c;
    cin>>n>>c;
    vector<ll> a(n), b(n-1);
    for(auto &i : a) {
        cin>>i;
    }
    for(auto &i : b) {
        cin>>i;
    }
    ll ans=1e9, days=0, bal=0;
    for(int i=0; i<n; i++) {
        if(bal>c) {
            break;
        }
        ll offer=(c-bal+a[i]-1)/a[i] + days;
        ans=min(ans, offer);
        if(i<n-1) {
            ll work=max((b[i]-bal+a[i]-1)/a[i], ll(0)); 
            days+=work+1;
            bal+=work*a[i];
            bal-=b[i];
        }
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

