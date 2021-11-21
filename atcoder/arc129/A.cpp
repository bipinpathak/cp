#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll calc(ll n, ll r) {
    ll ans=0, curr=1;
    while(curr<=min(n, r)) {
        if(curr&n) {
            ll low=curr, high=2*curr-1;
            high=min(high, r);
            ans+=high-low+1;
        }
        curr<<=1;
    }
    return ans;
}

void solve() {
    ll n, l, r;
    cin>>n>>l>>r;
    cout<<calc(n, r)-calc(n, l-1)<<endl;
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
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

