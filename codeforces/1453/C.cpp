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
	ll n;
	cin>>n;
	vector<vector<ll>> a(n, vector<ll> (n)), x(10, {n, -1}), y(10, {n, -1});
	vector<ll> ans(10, 0);
	for(ll i=0; i<n; i++) {
		string s;
		cin>>s;
		for(ll j=0; j<n; j++) {
			ll num=s[j]-'0';
			a[i][j]=num;
			x[num][0]=min(x[num][0], i);
			x[num][1]=max(x[num][1], i);
			y[num][0]=min(y[num][0], j);
			y[num][1]=max(y[num][1], j);
		}
	}
	for(ll i=0; i<n; i++) {
		for(ll j=0; j<n; j++) {
			ll num=a[i][j], hori=max(j, n-1-j), verti=max(i, n-1-i);
			for(auto x2 : x[num]) {
				ans[num]=max(ans[num], hori*abs(i-x2));
			}
			for(auto y2 :y[num]) {
				ans[num]=max(ans[num], verti*abs(j-y2));
			}
		}
	}
	for(auto i : ans) {
		cout<<i<<" ";
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

