#include "bits/stdc++.h"
using namespace std;
using ll = long long;


ll power(ll a, ll x, ll mod) {
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

ll modInv(ll a, ll mod) {
	return power(a, mod-2, mod);
}
void solve() {
    int k;
    cin>>k;
    ll mod=1e9+7;
    ll total=power(2, k, mod-1);
    total-=2;
    if(total<0) {
        total+=mod-1;
    }
    ll ans=power(4, total, mod);
    ans=(ans*6)%mod;
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

