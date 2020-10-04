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
void solve() {
	int n, m;
	cin>>n>>m;
	vector<vector<ll>> grid(n, vector<ll> (m));
	for(auto &row : grid) {
		for(auto &col : row) {
			cin>>col;
		}
	}
	ll ans=0;
	for(int i=0; 2*i<n-1; i++) {
		for(int j=0; 2*j<m-1; j++) {
			vector<ll> num={grid[i][j], grid[n-1-i][j], grid[i][m-1-j], grid[n-1-i][m-1-j]};
			sort(num.begin(), num.end());
			for(int k=0; k<4; k++) {
				ans+=abs(num[k]-num[1]);
			}
		}
	}
	if(n%2) {
		for(int j=0; 2*j<m-1; j++) {
			ans+=abs(grid[n/2][j]-grid[n/2][m-1-j]);
		}
	}
	if(m%2) {
		for(int i=0; 2*i<n-1; i++) {
			ans+=abs(grid[i][m/2]-grid[n-1-i][m/2]);
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

