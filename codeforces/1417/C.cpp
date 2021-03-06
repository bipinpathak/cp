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
	int n;
	cin>>n;
	vector<int> a(n+1);
	vector<vector<int>> index(n+1, {0});
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		index[a[i]].push_back(i);
	}
	for(int i=1; i<=n; i++) {
		index[i].push_back(n+1);
	}
	vector<int> ans(n+1, -1);
	for(int i=1; i<=n; i++) {
		int diff=index[i][1]-index[i][0];
		for(int j=1; j+1<(int) index[i].size(); j++) {
			diff=max(diff, index[i][j+1]-index[i][j]);
		}
		while(diff<=n && ans[diff]==-1) {
			ans[diff]=i;
			diff++;
		}
	}
	for(int i=1; i<=n; i++) {
		cout<<ans[i]<<" ";
	}
	cout<<endl;
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

