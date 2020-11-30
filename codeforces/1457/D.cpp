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
	int n;
	cin>>n;
	vector<ll> a(n), pre(n);
	for(int i=0; i<n; i++) {
		cin>>a[i];
		pre[i]=a[i];
		if(i) {
			pre[i]^=pre[i-1];
		}
	}
	for(int i=0; i+1<n; i++) {
		ll mid=a[i]^a[i+1];
		if((i && a[i-1]>mid) || (i+2<n && mid>a[i+2])) {
			cout<<1<<endl;
			return;
		}
	}
	int ans=-1;
	for(int i=0; i<n; i++) {
		for(int j=i; j<n; j++) {
			for(int k=j+1; k<n; k++) {
				ll left=pre[j]^(i?pre[i-1]:0), right=pre[k]^pre[j];
				if(left>right) {
					if(ans==-1) {
						ans=n;
					}
					ans=min(ans, k-i-1);
				}
			}
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

