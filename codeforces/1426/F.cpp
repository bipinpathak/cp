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
	int n;
	cin>>n;
	vector<char> a(n);
	for(auto &i : a) {
		cin>>i;
	}
	ll c=0, bc=0, abc=0, count=1;
	for(int i=n-1; i>=0; i--) {
		if(a[i]=='c') {
			c=(c+count)%p;
		} else if(a[i]=='b') {
			bc=(bc+c)%p;
		} else if(a[i]=='a') {
			abc=(abc+bc)%p;
		} else {
			abc=((3*abc)%p+bc)%p;
			bc=((3*bc)%p+c)%p;
			c=((3*c)%p+count)%p;
			count=(count*3)%p;
		}
	}
	cout<<abc<<endl;
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

