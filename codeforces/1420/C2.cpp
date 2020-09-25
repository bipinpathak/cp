#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> fac(1);
ll power(ll a, ll x, ll p) {
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
ll modInv(ll a, ll p) {
	return power(a, p-2, p);
}
ll ncr(ll n, ll r, ll p) {
	ll ans=1;	
	if(r!=0 && r!=n) {
		ans=fac[n]*modInv(r, p)%p*modInv(n-r, p)%p;
	}
	return ans;
}
void update(vector<ll> &a, ll &ans) {
	int i, j;
	ll zero=0;
	cin>>i>>j;
	if(i==j) {
		return;
	} else if(j==i+1) {
		ans-=max(zero, a[i-1]-a[i])+max(zero, a[i]-a[i+1])+max(zero, a[j]-a[j+1]);
		swap(a[i], a[j]);
		ans+=max(zero, a[i-1]-a[i])+max(zero, a[i]-a[i+1])+max(zero, a[j]-a[j+1]);
	} else {
		ans-=max(zero, a[i-1]-a[i])+max(zero, a[i]-a[i+1])+max(zero, a[j-1]-a[j])+max(zero, a[j]-a[j+1]);
		swap(a[i], a[j]);
		ans+=max(zero, a[i-1]-a[i])+max(zero, a[i]-a[i+1])+max(zero, a[j-1]-a[j])+max(zero, a[j]-a[j+1]);
	}
	return;
}
void solve() {
	int n, q;
	cin>>n>>q;
	vector<ll> a(n+2);
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	ll ans=0;
	for(int i=1; i<=n; i++) {
		ans+=max((ll)0, a[i]-a[i+1]);
	}
	cout<<ans<<endl;
	while(q--) {
		update(a, ans);
		cout<<ans<<endl;
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

