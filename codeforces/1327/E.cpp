#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p=998244353;

ll power(ll a, ll x) {
	ll ans=1;
	while(x) {
		if(x&1) {
			ans=(ans*a)%p;
		}
		x=x>>1;
		a=(a*a)%p;
	}
	return ans;
}

void solve() {
	ll n;
	cin>>n;
	for(ll i=1; i<=n; i++) {
		ll ans=0;
		int extra=n-i;
		if(extra>=2) {
			ans=(ans+(81*(extra-1)*power(10, extra-1))%p)%p;
		}
		if(extra>=1) {
			ans=(ans+18*power(10, extra))%p;
		}
		if(extra==0) {
			ans=10;
		}
		cout<<ans<<" ";
	}
	cout<<endl;
    return;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while(t--) {
        solve();
    }
    return 0;
}

