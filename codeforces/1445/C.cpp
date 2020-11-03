#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
vector<ll> fac;
ll p=1e18;
ll gcd(ll x, ll y) {
	if(x==0) {
		return y;
	}
	return gcd(y%x, x);
}
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
ll modInv(ll a) {
	return power(a, p-2);
}
ll ncr(ll n, ll r) {
	ll ans=1;	
	if(r!=0 && r!=n) {
		ans=fac[n]*modInv(fac[r])%p*modInv(fac[n-r])%p;
	}
	return ans;
}
void pre(int n) {
	ll x=1;
	fac.push_back(x);
	for(ll i=1; i<=n; i++) {
		x=(x*i)%p;
		fac.push_back(x);
	}
	return;
}
void solve() {
	ll p, q, ans;
	cin>>p>>q;
	ans=p;
	if(p%q==0) {
		ll option=p;
		ans=0;
		while(option%q==0) {
			option/=q;
		}
		ans=max(ans, option);
		for(ll i=2; i*i<=q; i++) {
			if(q%i==0) {
				option=p;
				while(option%q==0) {
					option/=i;
				}
				ans=max(ans, option);
				option=p;
				while(option%q==0) {
					option/=q/i;
				}
				ans=max(ans, option);
			}
		}
	}
	cout<<ans<<endl;
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
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

