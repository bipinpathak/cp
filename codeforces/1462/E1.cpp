#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> fac;
ll p=1e9+7;
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
	ll ans=(n*(n-1))/2;	

	return ans;
}
void pre(ll n) {
	ll x=1;
	fac.push_back(x);
	for(ll i=1; i<=n; i++) {
		x=(x*i)%p;
		fac.push_back(x);
	}
	return;
}
void solve() {
	ll n, m=3, k=2;
	cin>>n;
	vector<ll> a(n);
	for(auto &i : a) {
		cin>>i;	
	}
	sort(a.begin(), a.end());
	ll left=0, right=0, ans=0;
	while(left<n) {
		while(right<n && a[right]-a[left]<=k) {
			right++;
		}
		if(right-left>=m) {
			ans=(ans+ncr(right-left-1, m-1));
		}
		left++;
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
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

