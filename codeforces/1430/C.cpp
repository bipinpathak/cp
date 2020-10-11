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
	int n;
	cin>>n;
	vector<vector<int>> ans;
	vector<int> f(n+1, 1);
	for(int i=n; i>2; i--) {
		if(f[i]==0) {
			continue;
		}
		while(f[i]>1) {
			ans.push_back({i, i});
			f[i]--;
		}
		ans.push_back({i, i-2});
		f[i]--;
		f[i-2]--;
		f[i-1]++;
	}
	while(f[2]>1) {
		ans.push_back({2, 2});
		f[2]--;
	}
	while(f[1]>1) {
		ans.push_back({1, 1});
		f[1]--;
	}
	if(f[1] && f[2]) {
		ans.push_back({1, 2});
	}
	cout<<(ans.back()[0]+ans.back()[1]+1)/2<<endl;
	for(auto step : ans) {
		cout<<step[0]<<" "<<step[1]<<endl;
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

