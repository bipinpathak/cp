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
int dfs(int node, int parent, int &ans, vector<vector<int>> &adjacency) {
	vector<int> depths;
	for(auto next : adjacency[node]) {
		if(next==parent) {
			continue;
		}
		depths.push_back(dfs(next, node, ans, adjacency));
	}
	sort(depths.rbegin(), depths.rend());
	if(depths.size()==0) {
		return 1;
	} 
	ans=max(ans, depths.front());
	if(depths.size()>1 && (node || depths[0]==depths[1])) {
		ans=max(ans, depths.front()+1);
	}
	return depths.back()+1;
}
void solve() {
	int n;
	cin>>n;
	vector<vector<int>> adjacency(n);
	for(int i=0; i<n-1; i++) {
		int u, v;
		cin>>u>>v;
		u--;
		v--;
		adjacency[u].push_back(v);
		adjacency[v].push_back(u);
	}
	int ans=0;
	dfs(0, -1, ans, adjacency);
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

