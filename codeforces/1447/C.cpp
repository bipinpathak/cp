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
	ll n, w;
	cin>>n>>w;
	vector<vector<ll>> a(n, vector<ll> (2));
	for(int i=0; i<n; i++) {
		cin>>a[i][0];
		a[i][1]=i+1;
	}
	sort(a.begin(), a.end());
	while(a.size() && a.back().front()>w) {
		a.pop_back();
	}
	ll sum=0;
	vector<int> ans;
	while(a.size()) {
		sum+=a.back().front();
		ans.push_back(a.back().back());
		a.pop_back();
		if(sum>=(w+1)/2) {
			cout<<ans.size()<<endl;
			for(auto i : ans) {
				cout<<i<<" ";
			}
			cout<<endl;
			return;
		}
	}
	cout<<-1<<endl;
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

