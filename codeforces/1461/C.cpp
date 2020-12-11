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

//Useful code starts//

void solve() {
	int n, m;
	cin>>n>>m;
	vector<int> a(n), b(n);
	for(auto &i : a) {
		cin>>i;
	}
	b=a;
	sort(b.begin(), b.end());
	int needed=0;
	for(int i=n-1; i>=0; i--) {
		if(a[i]!=b[i]) {
			needed=i+1;
			break;
		}
	}
	double p, ans=1;
	int r;
	for(int i=0; i<m; i++) {
		cin>>r>>p;
		if(r>=needed) {
			ans*=1-p;
		}
	}
	if(needed==0) {
		ans=0;
	}
	cout<<1-ans<<endl;
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

