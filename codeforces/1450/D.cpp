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
	vector<int> a(n), left(n, -1), right(n, n), limit(n+1, 0);
	for(auto &i : a) {
		cin>>i;
	}
	stack<int> active;
	for(int i=n-1; i>=0; i--) {
		while(active.size() && a[active.top()]>a[i]) {
			left[active.top()]=i;
			active.pop();
		}
		active.push(i);
	}
	while(active.size()) {
		active.pop();
	}
	for(int i=0; i<n; i++) {
		while(active.size() && a[active.top()]>a[i]) {
			right[active.top()]=i;
			active.pop();
		}
		active.push(i);
	}
	for(int i=0; i<n; i++) {
		int option=right[i]-left[i]-1;
		limit[a[i]]=max(limit[a[i]], option);
	}
	for(int i=2; i<=n; i++) {
		limit[i]=min(limit[i], limit[i-1]);
	}
	string ans;
	for(int k=1; k<=n; k++) {
		if(limit[n-k+1]>=k) {
			ans.push_back('1');
		} else {
			ans.push_back('0');
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

