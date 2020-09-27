#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> fac(1e6);
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
	ll n, target;
	cin>>n>>target;
	vector<ll> a(n);
	map<ll, vector<ll>> store;
	for(int i=0; i<n; i++) {
		cin>>a[i];
		store[a[i]].push_back(i);
	}
	vector<int> assign(n, 0);
	if(target%2==0 && store.find(target/2)!=store.end()) {
		int k=store[target/2].size()/2;
		for(auto i : store[target/2]) {
			k--;
			assign[i]=1;
			if(k<=0) {
				break;
			}
		}
		store.erase(target/2);
	}
	for(int i=n-1; i>=0; i--) {
		if(!assign[i]) {
			if(store.find(target-a[i])!=store.end()) {
				for(auto j : store[a[i]]) {
					assign[j]=1;
				}
				store.erase(a[i]);
				store.erase(target-a[i]);
			}
		}
	}
	for(auto i : assign) {
		cout<<i<<" ";
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

