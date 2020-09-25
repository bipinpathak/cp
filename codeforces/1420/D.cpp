#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> fac(1e6);
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
	if(n<r) {
		return 0;
	}
	ll ans=1;	
	if(r!=0 && r!=n) {
		ans=(((fac[n]*modInv(fac[r], p))%p)*modInv(fac[n-r], p))%p;
	}
	return ans;
}
void solve() {
	int n, k, p=998244353, active=0;
	ll ans=0;
	fac[0]=1;
	for(ll i=1; i<1e6; i++) {
		fac[i]=(fac[i-1]*i)%p;
	}
	cin>>n>>k;
	map<int, pair<int, int>> time;
	while(n--) {
		int start, end;
		cin>>start>>end;
		time[start].first++;
		time[end].second++;
	}
	for(auto t : time) {
		active+=t.second.first;
		if(active>=k) {
			ans=(ans+ncr(active, k, p)-ncr(active-t.second.first, k, p))%p;
			ans=(ans+p)%p;
		}
		active-=t.second.second;
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

