#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
	int n, k;
	cin>>n>>k;
	vector<int> a(n);
	for(auto &i : a) {
		cin>>i;
	}
	sort(a.rbegin(), a.rend());
	int extra=0, total=0;
	for(int i=0; i<n; i++) {
		if(a[i]==a[k-1]) {
			total++;
			if(i>=k) {
				extra++;
			}
		}
	}
	cout<<ncr(total, total-extra)<<endl;
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
	pre(1000);
    while(t--) {
        solve();
    }
    return 0;
}

