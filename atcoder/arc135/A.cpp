#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll mod=998244353;

ll power(ll a, ll x) {
    a%=mod;
    if(a==0) {
        return a;
    }
	ll ans=1;
	while(x) {
		if(x&1) {
			ans=(ans*a)%mod;
		}
		x=x>>1;
		a=(a*a)%mod;
	}
	return ans;
}

void solve() {
    ll x;
    cin>>x;
    map<ll, ll> active;
    active[x]=1;
    while(active.rbegin()->first>3) {
        x=active.rbegin()->first;
        ll f=active.rbegin()->second;
        active.erase(x);
        ll y=x/2;
        x-=y;
        active[x]+=f;
        active[y]+=f;
    }
    ll ans=1;
    for(auto &[val, p] : active) {
        ans=(ans*power(val, p))%mod;
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
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

