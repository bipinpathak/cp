#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> fac(1e6);
ll p=1e9+7;
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
void pre() {
	fac[0]=1;
	for(int i=1; i<(int) fac.size(); i++) {
		fac[i]=(fac[i-1]*i)%p;
	}
}
void go(ll n, ll &low, ll &high) {
	low=9;
	high=0;
	while(n) {
		low=min(low, n%10);
		high=max(high, n%10);
		n/=10;
	}
	return;
}
void solve() {
	ll a, k, low, high;
	cin>>a>>k;
	go(a, low, high);
	k--;
	while(k-- && low) {
		a+=low*high;
		go(a, low, high);
	}
	cout<<a<<endl;
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

