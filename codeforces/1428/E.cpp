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
ll divide(ll x, vector<ll>a) {
	ll count=0;
	for(auto i : a) {
		count+=(i+x-1)/x;
	}
	return count;
}
ll cost(ll a, ll p) {
	ll rem=a%p;
	a/=p;
	p-=rem;
	return p*pow(a, 2)+rem*pow(a+1, 2);
}
ll benifit(ll a, ll p) {
	return cost(a, p)-cost(a, p+1);
}
void solve() {
	int n, k;
	cin>>n>>k;
	vector<ll> a(n), parts(n, 1);
	priority_queue<pair<ll, ll>> x;
	ll ans=0;
	for(ll i=0; i<n; i++) {
		cin>>a[i];
		ans+=cost(a[i], parts[i]);
		x.push(make_pair(benifit(a[i], parts[i]), i));
	}
	k-=n;
	while(k--) {
		auto i=x.top().s;
		ans-=x.top().f;
		x.pop();
		parts[i]++;
		x.push(make_pair(benifit(a[i], parts[i]), i));
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
