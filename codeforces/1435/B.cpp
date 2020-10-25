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
void solve() {
	int n, m;
	cin>>n>>m;
	vector<vector<int>> rows(n, vector<int> (m)), cols(m, vector<int> (n));
	for(auto &i : rows) {
		for(auto &j : i) {
			cin>>j;
		}
	}
	for(auto &i : cols) {
		for(auto &j : i) {
			cin>>j;
		}
	}
	vector<vector<int>> ans(n, vector<int> (m));
	for(int i=0; i<n; i++) {
		set<int> elements;
		for(int j=0; j<m; j++) {
			elements.insert(cols[j][i]);
		}
		for(int j=0; j<n; j++) {
			set<int> curr;
			for(auto x : rows[j]) {
				if(elements.find(x)==elements.end()) {
					break;
				}
				curr.insert(x);
			}
			if((int)curr.size()==m) {
				ans[i]=rows[j];
			}
		}
	}
	for(auto i : ans) {
		for(auto j : i) {
			cout<<j<<" ";
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

