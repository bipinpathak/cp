#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
void no() {
	cout<<"NO"<<endl;
	return;
}
void solve() {
	int n;
	cin>>n;
	vector<int> events(2*n);
	for(int i=0; i<2*n; i++) {
		char c;
		cin>>c;
		if(c=='-') {
			cin>>events[i];
		}
	}
	stack<int> place;
	for(int i=2*n-1; i>=0; i--) {
		if(events[i]) {
			if(place.size() && events[i]>place.top()) {
				no();
				return;
			} else {
				place.push(events[i]);
				events[i]=0;
			}
		} else {
			if(place.size()) {
				events[i]=place.top();
				place.pop();
			} else {
				no();
				return;
			}
		}
	}
	cout<<"YES"<<endl;
	for(auto i : events) {
		if(i) {
			cout<<i<<" ";
		}
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
    while(t--) {
        solve();
    }
    return 0;
}

