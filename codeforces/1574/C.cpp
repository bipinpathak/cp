#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<ll> a(n);
    ll total=0;
    for(auto &i : a) {
        cin>>i;
        total+=i;
    }
    sort(a.begin(), a.end());
    int m;
    cin>>m;
    while(m--) {
        ll x, y;
        cin>>x>>y;
        ll ans=0, extra=0;
        if(x+y>total) {
            extra=x+y-total;
            ans+=extra;
        }
        ll high=lower_bound(a.begin(), a.end(), x)-lower_bound(a.begin(), a.end(), 0);
        if(high==n || !(a[high]>=x && a[high]<=total+extra-y)) {
            ll needed=1e18;
            if(high!=n) {
                needed=min(needed, a[high]-total+y);
            }
            high--;
            if(high!=-1) {
                needed=min(needed, x-a[high]);
            }
            needed-=extra;
            needed=max(needed, (ll)0);
            ans+=needed;
        }
        cout<<ans<<endl;
    }
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

