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
	ll x, y, d, ans=0;
	cin>>x>>y;
	vector<ll> c(6);
	for(auto &i : c) {
		cin>>i;
	}
	for(int i=0; i<12; i++) {
		c[0]=min(c[0], c[1]+c[5]);
		c[1]=min(c[1], c[0]+c[2]);
		c[2]=min(c[2], c[1]+c[3]);
		c[3]=min(c[3], c[2]+c[4]);
		c[4]=min(c[4], c[3]+c[5]);
		c[5]=min(c[5], c[0]+c[4]);
	}
	d=min(abs(x), abs(y));
	if(d) {
		if(x>=0) {
			x-=d;
			if(y>=0) {
				ans=d*c[0];
				y-=d;
			}
			else {
				ans=d*(c[4]+c[5]);
				y+=d;
			}
		} else {
			x+=d;
			if(y>=0) {
				ans=d*(c[1]+c[2]);
				y-=d;
			} else {
				ans=d*c[3];
				y+=d;
			}
		}
	}
	if(x) {
		ans+=abs(x)*(x>0?c[5]:c[2]);
	} else {
		ans+=abs(y)*(y>0?c[1]:c[4]);
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

