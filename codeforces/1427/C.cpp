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
struct celeb{
	int t, x, y;
};
bool custom(celeb a, celeb b) {
	return a.t<b.t;
}
void solve() {
	int r, n;
	cin>>r>>n;
	vector<celeb> a(n);
	for(auto &i : a) {
		cin>>i.t>>i.x>>i.y;
	}
	sort(a.begin(), a.end(), custom);
	vector<int> ans(n, 1), maxi(n);
	int high=0;
	for(int i=n-1; i>=0; i--) {
		int j;
		for(j=i+1; j<=i+2*r && j<n; j++) {
			int distance=abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y);
			if(distance<=a[j].t-a[i].t) {
				ans[i]=max(ans[i], 1+ans[j]);
			}
		}
		if(j<n) {
			ans[i]=max(ans[i], 1+maxi[j]);
		}
		high=max(high, ans[i]);
		maxi[i]=high;
	}
	high=0;
	for(int i=0; i<n; i++) {
		if(abs(a[i].x-1)+abs(a[i].y-1)<=a[i].t) {
			high=max(high, ans[i]);
		}
	}
	cout<<high<<endl;
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

