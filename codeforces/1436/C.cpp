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
	int n, x, pos;
	cin>>n>>x>>pos;
	int big=0, small=0, left=0, right=n;
	while(left<right) {
		int middle=(left+right)/2;
		if(middle>pos) {
			big++;
			right=middle;
		} else if(middle==pos) {
			left=middle+1;
		}	else {
			small++;
			left=middle+1;
		}
	}
	ll ans=1, i, p=1e9+7;
	for(i=x-1; i>=x-small; i--) {
		ans=(ans*i)%p;
	}
	for(i=n-x; i>=n-x-big+1; i--) {
		ans=(ans*i)%p;
	}
	for(i=n-big-small-1; i>=1; i--) {
		ans=(ans*i)%p;
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

