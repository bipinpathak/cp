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
int check(vector<string> &grid, string s) {
	int count=0, n=grid.size();
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			int key=(i+j)%3;
			if(grid[i][j]=='.' || s[key]=='B') {
				continue;
			}
			if(grid[i][j]!=s[key]) {
				count++;
			}
		}
	}
	return count;
}
void solve() {
	int n;
	cin>>n;
	vector<string> grid(n);
	for(auto &i : grid) {
		cin>>i;
	}
	string ans;
	int count=n*n, choice;
	choice=check(grid, "BOX");
	if(choice<count) {
		ans="BOX";
		count=choice;
	}
	choice=check(grid, "OXB");
	if(choice<count) {
		ans="OXB";
		count=choice;
	}
	choice=check(grid, "XBO");
	if(choice<count) {
		ans="XBO";
		count=choice;
	}
	choice=check(grid, "BXO");
	if(choice<count) {
		ans="BXO";
		count=choice;
	}
	choice=check(grid, "XOB");
	if(choice<count) {
		ans="XOB";
		count=choice;
	}
	choice=check(grid, "OBX");
	if(choice<count) {
		ans="OBX";
		count=choice;
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			int key=(i+j)%3;
			if(ans[key]=='B' || grid[i][j]=='.') {
				continue;
			}
			grid[i][j]=ans[key];
		}
	}
	for(auto &i : grid) {
		cout<<i<<endl;
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

