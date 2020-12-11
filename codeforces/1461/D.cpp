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

//Useful code starts//

void go(vector<ll> &a, set<ll> &possible) {
	if(a.size()==0) {
		return;
	}
	int n=a.size();
	ll low=1e6, high=1, sum=0, mid;
	for(int i=0; i<n; i++) {
		sum+=a[i];
		low=min(low, a[i]);
		high=max(high, a[i]);
	}
	possible.insert(sum);
	mid=(low+high)/2;
	vector<ll> left, right;
	for(int i=0; i<n; i++) {
		if(a[i]<=mid) {
			left.push_back(a[i]);
		} else {
			right.push_back(a[i]);
		}
	}
	if(left.size() && right.size()) {
		go(left, possible);
		go(right, possible);
	}
	return;
}

void solve() {
	int n, q;
	cin>>n>>q;
	vector<ll> a(n), sum(n);
	for(auto &i : a) {
		cin>>i;
	}
	for(int i=0; i<n; i++) {
		sum[i]=a[i];
		if(i) {
			sum[i]+=sum[i-1];
		}
	}
	set<ll> possible;
	go(a, possible);
	for(int i=0; i<q; i++) {
		cin>>n;
		if(possible.find(n)==possible.end()) {
			cout<<"NO"<<endl;
		} else {
			cout<<"YES"<<endl;
		}
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

