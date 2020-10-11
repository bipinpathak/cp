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
vector<vector<int>> store(1001, vector<int> (3));
vector<int> possible(1001);
void solve() {
    int n;
	cin>>n;
	if(!possible[n]) {
		cout<<-1;
	} else {
		for(auto i : store[n]) {
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
	vector<int> rooms={3, 5, 7};
	possible[0]=1;
	for(int i=1; i<=1000; i++) {
		for(auto room : rooms) {
			if(i-room>=0 && possible[i-room]) {
				store[i]=store[i-room];
				store[i][room/2-1]++;
				possible[i]=1;
				break;
			}
		}
	}
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

