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
	ll k;
	cin>>k;
	if(k%2) {
		cout<<-1<<endl;
		return;
	} 
	vector<int> binary;
	while(k) {
		binary.push_back(k%2);
		k/=2;
	}
	int count=0;
	vector<int> ans;
	for(int i=0; i<(int) binary.size(); i++) {
		if(binary[i]) {
			ans.push_back(i-1);
			count++;
		}
	}
	count--;
	while(count--) {
		ans.push_back(1);
	}
	int levels=1;
	for(auto &i : ans) {
		levels+=i;
		i=levels;
	}
	vector<int> out(levels, 0);
	out[0]=1;
	for(auto i : ans) {
		out[i-1]=1;
	}
	cout<<levels<<endl;
	for(auto &i : out) {
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

