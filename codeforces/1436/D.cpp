#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
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
void dfs(int node, vector<vector<int>> &adjacency, vector<ll> &leaves, vector<ll> &a, vector<ll> &visited) {
	if(!visited[node]) {
		visited[node]=1;
		for(auto next : adjacency[node]) {
			dfs(next, adjacency, leaves, a, visited);
			a[node]+=a[next];
			leaves[node]+=leaves[next];
		}
		if(leaves[node]==0) {
			leaves[node]=1;
		}
	}
	return;
}
void solve() {
	int n;
	cin>>n;
	vector<vector<int>> adjacency(n+1);
	for(int i=2; i<=n; i++) {
		int p;
		cin>>p;
		adjacency[p].push_back(i);
	}
	vector<ll> leaves(n+1), a(n+1), visited(n+1);
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	dfs(1, adjacency, leaves, a, visited);
	ll ans=0;
	for(int i=1; i<=n; i++) {
		ans=max(ans, (a[i]+leaves[i]-1)/leaves[i]);
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

