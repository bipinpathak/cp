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
	int k;
	cin>>k;
	vector<vector<ll>> grid;
	for(int i=0; i<k; i++) {
		int n;
		ll sum=0;
		cin>>n;
		grid.push_back({});
		for(int j=0; j<n; j++) {
			ll x;
			cin>>x;
			sum+=x;
			grid.back().push_back(x);
		}
		grid.back().push_back(sum);
	}
	map<ll, pair<int, int>> seen;
	for(int i=0; i<k; i++) {
		for(int j=0; j<(int)grid[i].size()-1; j++) {
			ll option=grid[i].back()-grid[i][j];
			if(seen.find(option)!=seen.end() && seen[option].first!=i) {
				cout<<"YES"<<endl;
				cout<<seen[option].first+1<<" "<<seen[option].second+1<<endl;
				cout<<i+1<<" "<<j+1<<endl;
				return;
			}
			seen[option]={i, j};
		}
	}
	cout<<"NO"<<endl;
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

