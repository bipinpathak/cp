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

//Useful code starts//

void solve() {
	int n, m;
	cin>>n>>m;
	vector<vector<int>> grid(n, vector<int> (m)), right(n, vector<int> (m)), left(n, vector<int> (m));
	for(auto &i : grid) {
		for(auto &j : i) {
			char c;
			cin>>c;
			if(c=='*') {
				j=1;
			} else {
				j=0;
			}
		}
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(grid[i][j]) {
				left[i][j]=1+((j-1)>=0?left[i][j-1]:0);
			} 
		}
	}
	for(int i=0; i<n; i++) {
		for(int j=m-1; j>=0; j--) {
			if(grid[i][j]) {
				right[i][j]=1+((j+1<m)?right[i][j+1]:0);
			}
		}
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			right[i][j]=min(right[i][j], left[i][j]);
		}
	}
	ll ans=0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(right[i][j]) {
				ll h=0;
				while(i+h<n && right[i+h][j]>=h+1) {
					h++;
				}
				ans+=h;
			}
		}
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
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

