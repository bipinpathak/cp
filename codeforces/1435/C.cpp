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
	vector<ll> a(6);
	for(auto &i : a) {
		cin>>i;
	}
	int n;
	cin>>n;
	vector<ll>  b(n);
	vector<pair<ll, int>> all;
	for(int i=0; i<n; i++) {
		cin>>b[i];
		for(auto j : a) {
			all.push_back({b[i]-j, i});
		}
	}
	sort(all.begin(), all.end());
	vector<int> f(n);
	int left=0, right=0;
	set<int> seen;
	for(int i=0; i<6*n; i++) {
		if(seen.find(all[i].second)==seen.end()) {
			seen.insert(all[i].second);
			right=i;
		}
	}
	for(int i=0; i<=right; i++) {
		f[all[i].second]++;
	}
	ll ans=all[right].first-all[left].first;
	while(right<6*n) {
		f[all[left].second]--;
		while(f[all[left].second]==0 && right<6*n) {
			right++;
			if(right<6*n) {
				f[all[right].second]++;
			}
		}
		left++;
		if(right<6*n) {
			ans=min(ans, all[right].first-all[left].first);
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
    while(t--) {
        solve();
    }
    return 0;
}

