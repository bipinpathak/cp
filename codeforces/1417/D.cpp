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
	ll n;
	cin>>n;
	vector<ll> a(n+1);
	ll sum=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		sum+=a[i];
	}
	if(sum%n) {
		cout<<-1<<endl;
		return;
	}
	vector<vector<ll>> operations;
	for(ll i=2; i<=n; i++) {
		if(a[i]%i) {
			ll needed=i-a[i]%i;
			operations.push_back({1, i, needed});
			a[0]-=needed;
			a[i]+=needed;
		}
		operations.push_back({i, 1, a[i]/i});
	}
	sum/=n;
	for(int i=2; i<=n; i++) {
		operations.push_back({1, i, sum});
	}
	cout<<operations.size()<<endl;
	for(auto o : operations) {
		for(auto i : o) {
			cout<<i<<" ";
		}
		cout<<endl;
	}
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

