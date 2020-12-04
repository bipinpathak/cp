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
	vector<ll> a(n);
	for(auto &i : a) {
		cin>>i;
	}
	ll maxi=0, maxdiff=0, ans=0;
	for(int i=1; i<n-1; i++) {
		if(abs(a[i+1]-a[i])+abs(a[i]-a[i-1])-abs(a[i+1]-a[i-1])>maxdiff) {
			maxdiff=abs(a[i+1]-a[i])+abs(a[i]-a[i-1])-abs(a[i+1]-a[i-1]);
			maxi=i;
		}
	}
	if(abs(a[n-1]-a[n-2])>maxdiff) {
		maxdiff=abs(a[n-1]-a[n-2]);
		maxi=n-1;
	} 
	if(abs(a[1]-a[0])>maxdiff) {
		maxi=0;
	}
	if(maxi==0) {
		a[0]=a[1];
	} else if(maxi==n-1) {
		a[n-1]=a[n-2];
	}  else {
		a[maxi]=(a[maxi-1]+a[maxi+1])/2;
	}
	for(int i=1; i<n; i++) {
		ans+=abs(a[i]-a[i-1]);
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

