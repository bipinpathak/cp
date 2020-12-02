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
    int n;
	cin>>n;
	vector<ll> a(n);
	for(auto &i : a) {
		cin>>i;
	}
	if(n%2) {
		cout<<"YES"<<endl<<n-1<<endl;
		for(int i=2; i+1<=n; i+=2) {
			cout<<1<<" "<<i<<" "<<i+1<<endl;
		}
		for(int i=2; i+1<=n; i+=2) {
			cout<<1<<" "<<i<<" "<<i+1<<endl;
		}
		return;
	}
	ll val=0;
	for(auto &i : a) {
		val^=i;
	}
	if(val) {
		cout<<"NO"<<endl;
		return;
	}
	cout<<"YES"<<endl<<n-3<<endl;
	for(int i=1; i+2<=n; i+=2) {
		cout<<i<<" "<<i+1<<" "<<i+2<<endl;
	}
	for(int i=1; i+1<=n-4; i+=2) {
		cout<<n<<" "<<i<<" "<<i+1<<endl;
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
    while(t--) {
        solve();
    }
    return 0;
}
