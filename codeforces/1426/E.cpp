#include <bits/stdc++.h>
#include <type_traits>
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
void go(vector<int> a, vector<int> b, set<pair<int, int>> lose, int &low, int ans) {
	for(auto edge : lose) {
		auto pass=lose;
		auto x=a, y=b;
		int weight=min(x[edge.first], y[edge.second]);
		x[edge.first]-=weight;
		y[edge.second]-=weight;
		pass.erase(edge);
		go(x, y, pass, low, ans-weight);
	}
	if(lose.size()==0) {
		low=min(low, ans);
	}
}
void solve() {
	int n;
	cin>>n;
	vector<int> a(3), b(3);
	for(auto &i : a) {
		cin>>i;
	}
	for(auto &i : b) {
		cin>>i;
	}
	int low=n, high=0;
	set<pair<int, int>> win, lose;
	for(int i=0; i<3; i++) {
		win.insert({i, (i+1)%3});
		lose.insert({i, i});
		lose.insert({i, (i+2)%3});
	}
	for(auto order : win) {
		high+=min(a[order.first], b[order.second]);
	}
	go(a, b, lose, low, n);
	cout<<low<<" "<<high<<endl;
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

