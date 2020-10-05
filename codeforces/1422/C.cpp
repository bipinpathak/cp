#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> fac(1e6);
ll p=1e9+7;
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
void pre() {
	fac[0]=1;
	for(int i=1; i<(int) fac.size(); i++) {
		fac[i]=(fac[i-1]*i)%p;
	}
}
void solve() {
	string s;
	cin>>s;
	int n=s.length();
	ll ans=0, build=0;
	vector<ll> ten(n), gp(n);
	ten[0]=gp[0]=1;
	for(int i=1; i<n; i++) {
		ten[i]=(ten[i-1]*10)%p;
		gp[i]=(gp[i-1]+ten[i])%p;
	}
	for(int i=0; i<n-1; i++) {
		build=(build*10%p+s[i]-'0')%p;
		ans=(ans+build*gp[n-2-i]%p)%p;
	}
	build=0;
	for(int i=n-1; i>0; i--) {
		build=(build+(s[i]-'0')*ten[n-1-i]%p)%p;
		ans=(ans+build*i%p)%p;
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
    while(t--) {
		solve();
    }
    return 0;
}

