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
void add(int i, int x, vector<int> &a) {
	int n=a.size();
	while(i<n) {
		a[i]+=x;
		i+=i&-i;
	}
}
int get(int i, vector<int> &a) {
	int ans=0;
	while(i) {
		ans+=a[i];
		i-=i&-i;
	}
	return ans;
}
void solve() {
	int n;
	ll count=0;
	string s;
	cin>>n>>s;
	vector<vector<int>> options(26);
	vector<int> ans(n+1);
	for(int i=0; i<n; i++) {
		options[s[i]-'a'].push_back(i+1);
	}
	for(int i=0; i<n; i++) {
		int val=s[i]-'a', choose;
		choose=options[val].back();
		options[val].pop_back();
		count+=(ll)get(choose, ans);
		add(choose, 1, ans);
	}
	cout<<count<<endl;
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

