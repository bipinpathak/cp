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
	int n;
	string s;
	cin>>n>>s;
	vector<int> left(n, 1), right(n, 1), possible(n);
	for(int i=0; i<n; i++) {
		if(s[i]=='<') {
			right[i]=0;
		} else if(s[i]=='>') {
			left[(i+1)%n]=0;
		} else {
			possible[i]=possible[(i+1)%n]=1;
		}
	}
	int c=0, ac=0;
	for(int i=0; i<n; i++) {
		if(right[i] && c==i) {
			c++;
		}
		if(left[i] && ac==i) {
			ac++;
		}
	}
	if(c==n || ac==n) {
		cout<<n<<endl;
		return;
	}
	c=0;
	for(auto i : possible) {
		c+=i;
	}
	cout<<c<<endl;
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

