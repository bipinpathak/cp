#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> fac;
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
	ll a, b;
	string s;
	cin>>a>>b>>s;
	while(s.size() && s.back()=='0') {
		s.pop_back();
	}
	reverse(s.begin(), s.end());
	while(s.size() && s.back()=='0') {
		s.pop_back();
	}
	vector<ll> gaps;
	ll d=0;
	for(auto i : s) {
		if(i=='0') {
			d++;
		} else if (d) {
			gaps.push_back(d);
			d=0;
		}
	}
	ll ans=0;
	if(s.size()) {
		ans+=a;
	}
	for(auto d : gaps) {
		ans+=min(a, d*b);
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

